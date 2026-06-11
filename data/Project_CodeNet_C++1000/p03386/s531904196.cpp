#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	ll a, b,k,ans;
	cin >> a >> b>>k;
	if (b - a + 1 <= k) {
		for (int i = a; i <= b; i++) {
			cout << i << endl;
		}
		return 0;
	}
	ll check1[105], check2[105];
	for (int i = 0; i < k; i++) {
		ans = a + i;
		check1[i] = ans;
		
	}
	for (int i = 0; i < k; i++) {
		cout << check1[i] << endl;
	}
	ll ans2;
	int flag = 0;
	for (int i = k-1; i >= 0; i--) {
		ans2 = b - i;
		
		for (int j = 0; j < k; j++) {
			if (check1[j] == ans2) {
				flag = 1;
			}
		}
		if (!flag) {
			cout << ans2 << endl;
		}
		flag = 0;
	}
	return 0;
}
