#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };
const int INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}

template<class T1, class T2> void chmin(T1 &a, T2 b) { if (a>b)a = b; }

template<class T1, class T2> void chmax(T1 &a, T2 b) { if (a<b)a = b; }
template<class T>
void Add(T &a, const T &b, const T &mod = 1000000007) {
	int val = ((a % mod) + (b % mod)) % mod;
	if (val < 0) { val += mod; }
	a = val;
}
////////////////////////////////////////
int N, M;
vector<int>G[100010];
int cnt[100010];
int dep[100010];
int main() {
	REP(i, 100010) {
		cnt[i] = 0;
		dep[i] = 0;
	}
	cin >> N >> M;
	REP(i, N +M- 1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		cnt[b]++;
	}
	stack<int>st;
	REP(i, N) {
		if (cnt[i] == 0) {
			st.push(i);
		}
	}
	vector<int>ans;
	while (st.size()) {
		int i = st.top(); st.pop();
		ans.push_back(i);
		for (auto j : G[i]) {
			cnt[j]--;
			if (cnt[j] == 0)st.push(j);
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int to : G[ans[i]]) {
			dep[to] = max(dep[to], dep[ans[i]] + 1);
		}
	}
	int root = ans[0];
	int res[100100];
	res[root] = -1;
	REP(i, N) {
		for (int j : G[ans[i]]) {
			if (dep[ans[i]] + 1 == dep[j]) {
				res[j] = ans[i];
			}
		}
	}
	REP(i, N) {
		cout << res[i] + 1 << endl;
	}
	return 0;
}