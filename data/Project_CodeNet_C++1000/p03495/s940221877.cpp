#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v(200000);
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		v.at(A - 1)++;
	}

	sort(v.begin(), v.end());
	//for (int i = 0; i < 3; i++) cout << v.at(i) << endl;

	int ans = 0;
	for (int i = v.size() - K - 1; i >= 0; i--) {
		if (!v.at(i)) break;
		else ans += v.at(i);
	}

	cout << ans << endl;
}