#include<iostream>
#include<vector>
using namespace std;
int L, sz = 0;
struct edge{ int u,v,w; };
vector<edge>e;

int main() {
	cin >> L; L--;
	if (L == 1) {
		cout << "2 2" << endl << "1 2 1" << endl << "1 2 0" << endl;
		return 0;
	}
	while ((1 << sz) <= L)sz++;
	int s = 1, t = sz;
	for (int i = 1; i < sz; i++) {
		e.push_back({ i,i + 1,1 << (sz - i - 1) });
		e.push_back({ i,i + 1,0 });
	}
	int w = 1 << (sz - 1);
	for (int p = sz - 2, i = 1; p >= 0; p--, i++) {
		if (L >> p & 1) {
			e.push_back({ s,i + 1,w });
			w += 1 << p;
		}
	}
	e.push_back({ s,t,L });
	cout << sz << ' ' << e.size() << endl;
	for (auto&& x : e)cout << x.u << ' ' << x.v << ' ' << x.w << endl;
	return 0;
}