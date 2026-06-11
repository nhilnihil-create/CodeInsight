#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

using i8 = char;
using u8 = unsigned char;
using i32 = int;
using u32 = unsigned int;
using i64 = long long int;
using u64 = unsigned long long int;

using pii = pair<i32, i32>;

#define LOOP_TYPE(s, n) decltype((n) - (s))
#define FOR(i, s, n) for (auto i = LOOP_TYPE(s, n)(s); i != LOOP_TYPE(s, n)(n); i++)
#define FORR(i, s, n) for (auto i = LOOP_TYPE(s, n)(n) - 1; i != LOOP_TYPE(s, n)(s) - 1; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) FORR(i, 0, n)
#define mp make_pair

constexpr int dx[4] = {0, -1, 0, 1};
constexpr int dy[4] = {-1, 0, 1, 0};

int main()
{
	i32 N, M;
	cin >> N >> M;

	vector<list<i32>> g(N + M);
	vector<list<i32>> rg(N + M);
	vector<i32> src(N, 0);	// 頂点iの入次数
	REP(i, N - 1 + M) {
		i32 u, v;
		cin >> u >> v;
		g[u - 1].emplace_back(v - 1);
		rg[v - 1].emplace_back(u - 1);
		src[v-1]++;
	}

	// 入次数が0の頂点をparentsに追加
	stack<i32> parents;
	REP(i, N) {
		if (src[i] == 0) parents.emplace(i);
	}

	// 入次数が0の頂点がなくなるまで繰り返す
	vector<i32> sorted(N);
	i32 index = 0;
	while (!parents.empty()) {
		i32 parent = parents.top();
		parents.pop();
		sorted[parent] = index++;
		for (auto& i : g[parent]) {
			src[i]--;
			if (src[i] == 0) parents.emplace(i);
		}
	}

	REP(i, N) {
		i32 maxOrder = -1;
		i32 parent = -1;
		for (auto j : rg[i]) {
			if (maxOrder < sorted[j]) {
				maxOrder = sorted[j];
				parent = j;
			}
		}
		printf("%d\n", parent + 1);
	}

	return 0;
}
