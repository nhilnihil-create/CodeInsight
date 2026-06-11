#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pi;

int N, M;
vector<vector<pi> > P;
vector<string> A;

void input_init(void) {
	cin >> N >> M;
	P.resize(N + 1);
	for (int i = 0; i < M; ++i) {
		int p, y;
		cin >> p >> y;
		P[p].push_back(make_pair(y, i));
	}
	A.resize(M);
}

void make_str(int p, int x, int idx) {
	string s1 = to_string(p);
	int rest = 6 - s1.length();
	string s2 = string(rest, '0') + s1;
	string s3 = to_string(x);
	rest = 6 - s3.length();
	string s4 = string(rest, '0') + s3;
	A[idx] = s2 + s4;
}

void solve(void) {
	for (int i = 1; i < (int)P.size(); ++i) {
		if (P[i].size() == 0)
			continue;
		sort(P[i].begin(), P[i].end());
		for (int j = 0; j < (int)P[i].size(); ++j) {
			make_str(i, j + 1, P[i][j].second);
		}
	}
}

int main(void) {
	input_init();
	solve();
	for (int i = 0; i < M; ++i)
		cout << A[i] << '\n';
	return 0;
}
