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
typedef pair<ll, ll> pll;
const ll INF = 1ll<<30;
const ll longINF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

int N;
vector<int> g[11234];
int cnt[11234], c[11234];
int ans[11234];

int main() {
	cin >> N;
	REP(i, N - 1) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
		cnt[a]++; cnt[b]++;
	}
	REP(i, N) scanf("%d", c + i);
	vector<pii> v;
	REP(i, N) v.push_back(pii(c[i], i));
	sort(ALL(v));
	
	memset(ans, -1, sizeof(ans));
	queue<int> que;
	REP(i, N) if (cnt[i] == 1) que.push(i);
	
	int pos = 0;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		
		ans[u] = v[pos++].se;
		cnt[u]--;
		for (int v : g[u]) {
			if (--cnt[v] == 1) que.push(v);
		}
	}
	
	cout << accumulate(c, c + N, 0) - *max_element(c, c + N) << endl;
	REP(i, N) printf("%d%c", c[ans[i]], i == N - 1 ? '\n' : ' ');
	
	return 0;
}
