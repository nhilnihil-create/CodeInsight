#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, X;
	cin >> N >> X;

	vector<int> v(N);
	int sum = 0;

	for (int i = 0; i < N; i++) {
		cin >> v.at(i);
		sum += v.at(i);
	}

	sort(v.begin(), v.end());

	int ans = N;
	ans += (X - sum) / v.front();

	cout << ans << endl;
}