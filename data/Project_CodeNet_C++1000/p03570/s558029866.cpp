#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int dp[(1<<26)];
string s;
int main(){
	cin>>s;
	int n=s.size();
	rep(i,(1<<26)) dp[i] = INF;
	dp[0] = 0;
	int cur = 0;
	for(int i=0;i<s.size();i++){
		cur ^= (1<<(s[i]-'a'));
		int v = dp[cur]+1;
		for(int j=0;j<26;j++){
			int cur2 = cur ^ (1<<j);
			v = min(v,dp[cur2]+1);
		}
		dp[cur] = min(dp[cur],v);
	}
	if(dp[cur]==0) dp[cur]=1;
	cout<<dp[cur]<<endl;
}