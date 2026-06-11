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

vector<lli> places[210000];
lli dp[210000];

void add(lli &a,lli b){a+=b; if(a>=MOD)a-=MOD;}

signed main(){

	lli N;cin>>N;

	vector<lli> c(N);
	REP(i,0,N)cin>>c[i];

	REP(i,0,210000)places[i].clear();
	REP(i,0,N)places[c[i]].push_back(i);

	dp[0]=1;

	for(lli i=1;i<=N;i++){
		//特に操作しない
		add(dp[i],dp[i-1]);

		//操作する
		lli color = c[i-1];
		lli it = lower_bound(places[color].begin(),places[color].end(),i-1)-places[color].begin();
		if(it>0){
			lli j = places[color][it-1];
			if((i-1)-j>1)add(dp[i],dp[j+1]);
		}
	}

	cout<<dp[N]<<endl;

	return 0;
}