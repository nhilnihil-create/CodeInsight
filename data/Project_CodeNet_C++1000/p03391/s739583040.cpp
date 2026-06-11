#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int N;
	cin >> N;
	ll A, B, ans = LLONG_MAX, sum = 0;
	for (int i = 0;i < N;i++) {
		cin >> A >> B;
		if (A > B)
			ans = min(ans, B);
		sum += A;
	}
	if (ans == LLONG_MAX)
		cout << 0 << endl;
	else
		cout << sum - ans << endl;
}