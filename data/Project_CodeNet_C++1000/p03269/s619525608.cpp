#include "bits/stdc++.h"
using namespace std;

struct edge {
	int From, To, Cost;
	edge(int A, int B, int C) : From(A), To(B), Cost(C) {}
};

int main() {
	int L;
	cin >> L;
	vector<edge> ANS;
	for (int i = 1; i <= 18; i++) {
		ANS.push_back(edge(i, i + 1, 0));
		ANS.push_back(edge(i, i + 1, 1 << (i - 1)));
	}
	int NOW = 0;
	if (L & (1 << 19)) {
		ANS.push_back(edge(19, 20, 0));
		ANS.push_back(edge(19, 20, 1 << 18));
		NOW = 1 << 19;
	}
	for (int i = 19; i >= 1; i--) {
		if (L & (1 << (i - 1))) ANS.push_back(edge(i, 20, NOW)), NOW += (1 << (i - 1));
	}
	cout << 20 << ' ' << ANS.size() << endl;
	for (edge E : ANS) cout << E.From << ' ' << E.To << ' ' << E.Cost << endl;
}