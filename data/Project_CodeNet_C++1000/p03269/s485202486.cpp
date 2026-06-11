#include<iostream>
#include<vector>
using namespace std;

int L, sz = 0;
struct Edge {
	int u, v, w;
};
vector<Edge> E;

int main() {
	scanf("%d", &L);
	L--;
	if (L == 1) {
		puts("2 2");
		puts("1 2 1");
		puts("1 2 0");
		return 0;
	}
	while ((1 << sz) <= L) sz++;
	int S = 1, T = sz;
	for (int i = 1; i < sz; i++) {
		E.push_back(Edge{ i, i + 1, 1 << (sz - i - 1) });
		E.push_back(Edge{ i, i + 1, 0 });
	}
	int w = 0;
	w = 1 << (sz - 1);
	for (int p = sz - 2, i = 1; p >= 0; p--, i++) {
		if (L >> p & 1) {
			E.push_back(Edge{ S, i + 1, w });
			w += 1 << p;
		}
	}
	E.push_back(Edge{ S, T, L });
	printf("%d %d\n", sz, (int)E.size());
	for (auto& t : E) printf("%d %d %d\n", t.u, t.v, t.w);
	
	return 0;
}