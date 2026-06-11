#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

string dp[10100];
//use[i] i本使ったときの最大数
lli use[10];
bool vis[10010];

signed main(){

	REP(i,0,10)use[i]=-1;

	lli n,m;
	cin>>n>>m;

	lli d[9]={2,5,5,4,5,6,3,7,6};

	REP(i,0,m){
		lli a;
		cin>>a;
		use[d[a-1]] = max(use[d[a-1]],a);
	}

	if(DEBUG){


		REP(i,0,10){
			cout<<use[i]<<endl;
		}
	}
	vis[0]=true;

	REP(i,0,n){
		if(!vis[i])continue;
		REP(j,0,10){
			if(use[j]==-1)continue;
			if(dp[i+j].size() < (dp[i]+to_string(use[j])).size()){
				dp[i+j] = dp[i]+to_string(use[j]);
			}
			else{
				dp[i+j] = max(dp[i]+to_string(use[j]),dp[i+j]);
			}
			vis[i+j]=true;
		}
	}

	if(DEBUG)REP(i,0,n)cout<<"i="<<i<<" dp="<<dp[i]<<endl;

	cout<<dp[n]<<endl;



	return 0;
}