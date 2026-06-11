#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int A, B, K;
	cin >> A >> B >> K;

	int m = min(A, B);
	vector<int> v;

	for (int i = 1; i <= m; i++) {
		if ((A % i == 0) && (B % i == 0)) {
			v.push_back(i);
		}
	}
	reverse(v.begin(), v.end());

	cout << v[K - 1] << endl;
}