#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define rep(i,n) for (int i=0;i<n;++i)
#define REP(i,n) for (int i=1;i<=n;++i)
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define F first
#define S second
#define read(x) scanf("%d",&x)
int n;
ll d[100005];
map<ll,int> m;
ll dp[100005];
int sz[100005];// subtree size
vector<pii> ans;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>d[i];m[d[i]]=i;sz[i]=1;
	}
	sort(d+1,d+n+1);reverse(d+1,d+n+1);
	memset(dp,0,sizeof(dp));
	for (int i=1;i<n;++i){
		int u=m[d[i]];
		ll want=d[i]+(sz[u]<<1)-n;
		if (!m.count(want)){
			cout<<-1<<endl;return 0;
		}
		int pa=m[want];
		ans.pb(mp(u,pa));
		sz[pa]+=sz[u];
		dp[pa]+=dp[u]+sz[u];
	}
	if (dp[m[d[n]]]!=d[n]){
		cout<<-1<<endl;return 0;
	}
	for (int i=0;i<n-1;++i) cout<<ans[i].F<<' '<<ans[i].S<<endl;
	return 0; 
}