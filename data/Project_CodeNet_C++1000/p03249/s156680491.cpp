#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cstdio>
#define int long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int n;
map<int,int>ret;
vector<pii>e;
signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=0LL,x;i<n;i++){
		cin>>x;
		ret[x]=i;
		e.pb(mp(x,i));
	}
	sort(e.rbegin(),e.rend());
	int x=e.back().F;
	vector<int>sz(n,1LL);
	vector<int>dp(n,0LL);
	vector<pii>ans;
	for(auto c:e){
		if(c.F!=x){
			if(sz[c.S]*2LL>=n)return puts("-1"),0;
			int p=c.F-(n-2LL*sz[c.S]);
			if(!ret.count(p))return puts("-1"),0;
			int pa=ret[p];
			dp[pa]+=dp[c.S]+sz[c.S];
			sz[pa]+=sz[c.S];
			ans.pb(mp(c.S+1LL,pa+1LL));
		}
	}
	if(dp[e.back().S]!=x)return puts("-1"),0;
	for(auto c:ans)cout<<c.F<<' '<<c.S<<endl;
	return 0;
}
