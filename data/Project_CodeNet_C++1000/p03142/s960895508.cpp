#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1ll<<30;
const ll longINF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

int N, M;
vector<int> g[112345], rg[112345];
int indeg[112345]; // 入次数
int par[112345];

int main() {
	cin >> N >> M;
	REP(i, N - 1 + M) {
		int A, B;
		scanf("%d %d", &A, &B);
		A--; B--;
		g[A].emplace_back(B); indeg[B]++;
		rg[B].emplace_back(A);
	}
	
	int st;
	REP(i, N) if (rg[i].empty()) st = i;
	par[st] = 0;
	
	queue<int> que;
	que.push(st);
	
	while (!que.empty()) {
		int u = que.front(); que.pop();
		
		for (int v : g[u]) {
			if (indeg[v] == 1) {
				que.push(v);
				par[v] = u + 1;
			}
			else {
				indeg[v]--;
			}
		}
	}
	
	REP(i, N) printf("%d\n", par[i]);
	
	return 0;
}
