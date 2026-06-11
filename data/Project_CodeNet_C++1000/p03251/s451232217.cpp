#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, M, X, Y;
	cin >> N >> M >> X >> Y;

	vector<int> x(N), y(M);
	for (int i = 0; i < N; i++) cin >> x.at(i);
	for (int i = 0; i < M; i++) cin >> y.at(i);
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int L, R;
	L = x.back() + 1;
	R = y.front();

	for (int i = L; i <= R; i++) {
		if ((i > X) && (i <= Y)) {
			cout << "No War" << endl;
			return 0;
		}
	}
	cout << "War" << endl;
}