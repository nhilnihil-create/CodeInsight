#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main() {
	long long N, M;
	priority_queue<long long> A;
	priority_queue<pair<long long, long long>> C;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A.push(-a);
	}
	for (int i = 0; i < M; i++) {
		int b, c;
		cin >> b >> c;
		C.push(make_pair(c, b));
	}
	while (!C.empty()) {
		auto c = C.top();
		C.pop();
		for (int i = 0; i < c.second; i++) {
			if (-A.top() >= c.first) {
				while (!C.empty()) {
					C.pop();
				}
				break;
			}
			A.pop();
			A.push(-c.first);
		}
	}
	long long ans = 0;
	while (!A.empty()) {
		ans += -A.top();
		A.pop();
	}
	cout << ans << endl;
	return 0;
}
