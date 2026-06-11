#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v.at(i);

	int a, b;
	auto x = v;
	sort(v.begin(), v.end());
	a = v.at(N / 2 - 1);
	b = v.at(N / 2);

	for (int i = 0; i < N; i++) {
		if (x.at(i) <= a) cout << b << endl;
		else cout << a << endl;
	}
}