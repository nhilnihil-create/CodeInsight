#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int ALP='z'-'a'+1,MAX_N=2e5,INF=1e8;
string S;
int N,opt[MAX_N+1],dp[1<<ALP],cnt[ALP];
int main(){
	cin>>S;
	N=(int)S.size();
	opt[0]=0;
	fill(dp,dp+(1<<ALP),INF);
	dp[0]=0;
	int b=0;
	REP(i,N){
		b^=1<<(S[i]-'a');
		opt[i+1]=dp[b]+1;
		REP(j,ALP){
			opt[i+1]=min(dp[b^(1<<j)]+1,opt[i+1]);
		}
		dp[b]=min(dp[b],opt[i+1]);
	}
	cout<<opt[N]<<endl;
}