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

#define P pair<lli,lli>

lli d[40][40];
lli c[600][600];

vector<pair<lli,lli>> hopeToC[3];

signed main(){

	lli N,C;
	cin>>N>>C;

	REP(i,0,C)REP(j,0,C)cin>>d[i][j];
	REP(i,0,N)REP(j,0,N){
		cin>>c[i][j];
		c[i][j]--;
	}

	lli ans = INF;
	REP(hope,0,C){
		lli cost[3];
		cost[0]=0,cost[1]=0,cost[2]=0;
		REP(y,0,N)REP(x,0,N){
			if(c[y][x] != hope){
				cost[(x+y)%3] += d[c[y][x]][hope];
			}
		}
		hopeToC[0].push_back(mp(cost[0],hope));
		hopeToC[1].push_back(mp(cost[1],hope));
		hopeToC[2].push_back(mp(cost[2],hope));
	}
	sort(hopeToC[0].rbegin(),hopeToC[0].rend());
	sort(hopeToC[1].rbegin(),hopeToC[1].rend());
	sort(hopeToC[2].rbegin(),hopeToC[2].rend());

	REP(i,0,C)REP(j,0,C)REP(k,0,C){
		if(hopeToC[0][i].second == hopeToC[1][j].second)continue;
		if(hopeToC[1][j].second == hopeToC[2][k].second)continue;
		if(hopeToC[2][k].second == hopeToC[0][i].second)continue;
		ans = min(ans,hopeToC[0][i].first+hopeToC[1][j].first+hopeToC[2][k].first);
	}
	cout<<ans<<endl;


	return 0;
}