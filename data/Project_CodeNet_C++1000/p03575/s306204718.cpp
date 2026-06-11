#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())
#define all(a) (a).begin(), (a).end()

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//print
#define pv(val) cerr << #val << '=' << (val) << endl

const int INF = 1e9;

bool was[60];
bool graph[60][60];
int N, M; 

void dfs(int v){
	if(was[v]) return ;

	was[v] = true;
	REP(i,N) if(graph[v][i]) dfs(i);

}



int main(void){

	cin >> N >> M;

	vector<int> a(M);
	vector<int> b(M);
	REP(i,M) cin >> a[i] >> b[i];

	REP(i,M) a[i]--;
	REP(i,M) b[i]--;


	int ans = 0;

	REP(i,M){
		REP(i,60) REP(j,60) graph[i][j] = false;
		REP(i,60) was[i] = false;

		REP(j,M){
			if(i == j) continue;
			graph[a[j]][b[j]] = true;
			graph[b[j]][a[j]] = true;
		}

		dfs(0);

		bool ok = false;
		REP(i,N) if(!was[i]) ok = true;

		if(ok) ans++;

	}

	cout << ans << endl;

	return 0;

}
