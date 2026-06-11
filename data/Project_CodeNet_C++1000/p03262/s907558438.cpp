#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	if (a < b)
		swap(a, b);
	if (a % b == 0) {
		return b;
	} else {
		return gcd(b, a % b);
	}
}

int main() {
	int N, X;
	cin >> N >> X;
	priority_queue<int> Q;
	Q.push(X);
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		Q.push(a);
	}
	int a = Q.top();
	Q.pop();
	int ans = a - Q.top();
	while (true) {
		a = Q.top();
		Q.pop();
		if (Q.empty())
			break;
		ans = gcd(ans, a - Q.top());
	}
	cout << ans << endl;
	return 0;
}
