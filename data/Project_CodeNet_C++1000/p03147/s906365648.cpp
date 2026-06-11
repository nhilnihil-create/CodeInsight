#include <cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll h[105];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int index = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (h[i] <= index) {
			index = h[i];
		}
		else {
			ans += h[i] - index;
			index = h[i];
		}
	}
	cout << ans << endl;
	return 0;
}
