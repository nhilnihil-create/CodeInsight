#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

const int INF = 1001001001;
//const ll INF = 1000000000000000000;

int main() {
	int a, b, k;
	cin >> a >> b >> k;

	int ans, cnt = 0;
	for (int i = min(a,b); i >= 1; i--) {
		if ((a % i == 0) && (b % i == 0)) cnt++;
		if (cnt == k) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	return 0;
} 