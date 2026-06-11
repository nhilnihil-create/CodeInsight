#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll a[55];
int main() {
	ll n;
	cin >> n;
	ll count = 1,sum = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			count *= 2;
		}
		sum *= 3;
	}
	cout << sum - count << endl;

	return 0;
}
