#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int64_t> v(N), d(N);
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		d.at(i) = n - i;
		v.at(i) = n;
	}

	sort(d.begin(), d.end());
	int64_t a = d.at(N / 2);

	int64_t ans = 0;
	for (int i = 0; i < N; i++) {
		int64_t n = i + a;
		ans += abs(v.at(i) - n);
	}

	cout << ans << endl;
}