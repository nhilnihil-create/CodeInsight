#include<iostream>
#include<vector>
using namespace std;

int L, sz = 0;
struct Edge { int u, v, w; };
vector<Edge>E;

int main() {
	cin >> L; L--;
	if (L == 1) {
		cout << "2 2" << endl << "1 2 1" << endl << "1 2 0" << endl;
		return 0;
	}
	while ((1 << sz) <= L)sz++;
	int S = 1, T = sz;
	for (int i = 1; i < sz; i++) {
		E.push_back({ i,i + 1,1 << (sz - i - 1) });
		E.push_back({ i,i + 1,0 });
	}
	int w = 0;
	w = 1 << (sz - 1);
	for (int p = sz - 2, i = 1; p >= 0; p--, i++) {
		if (L >> p & 1) {
			E.push_back({ S,i + 1,w });
			w += 1 << p;
		}
	}
	E.push_back({ S,T,L });
	cout << sz << ' ' << E.size() << endl;
	for (auto&& t : E)cout << t.u << ' ' << t.v << ' ' << t.w << endl;

	return 0;
}