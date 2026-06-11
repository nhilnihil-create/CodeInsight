#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll a[100005];
ll b[100005];
ll c[100005];
int main(void) {
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		int x = lower_bound(a + 0, a + n, b[i]) - a;
		int y = upper_bound(c + 0, c + n, b[i])-c;
		sum += x * (n - y);
	}
	cout << sum << endl;
	return 0;
}
