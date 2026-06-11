#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v(M);
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		for (int j = 0; j < K; j++) {
			int A;
			cin >> A;
			v[A - 1]++;
		}
	}

	cout << count(v.begin(), v.end(), N) << endl;
}