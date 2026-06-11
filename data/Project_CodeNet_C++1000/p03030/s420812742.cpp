#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N;
	cin >> N;

	vector<tuple<string, int, int>> v(N);
	for (int i = 0; i < N; i++) {
		string S;
		int P;
		cin >> S >> P;
		P *= -1;
		get<0>(v[i]) = S;
		get<1>(v[i]) = P;
		get<2>(v[i]) = i + 1;
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		cout << get<2>(v[i]) << endl;
	}
}