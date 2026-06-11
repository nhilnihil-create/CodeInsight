
// C - Modulo Summation

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	int ans = 0;

	int a;
	for (int i=0; i<N; i++) {
		cin >> a;
		ans += a-1;
	}

	cout << ans << endl;

	return 0;
}