#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K, ans;
	cin >> N >> K;
	ans = 1;
	for (int i=0; i<N; i++) {
		ans += min(ans, K);
	}
	cout << ans << endl;
}
