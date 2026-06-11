#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int64_t N, M;
	cin >> N >> M;

	vector<pair<int64_t, int64_t>> v(N);
	for (int64_t i = 0; i < N; i++) {
		cin >> v.at(i).first >> v.at(i).second;
	}
	sort(v.begin(), v.end());

	//for (int i = 0; i < N; i++) {
	//	cout << v.at(i).first << ' ' << v.at(i).second << endl;
	//}

	int64_t sum = 0;
	int64_t cnt = M;
	for (int64_t i = 0; i < N; i++) {
		if (!M) break;
		int64_t A, B;
		A = v.at(i).first;
		B = v.at(i).second;
		if (M < B) {
			sum += A * M;
			M = 0;
		}
		else {
			sum += A * B;
			M -= B;
		}
		//cout << M << endl;
	}

	cout << sum << endl;
}