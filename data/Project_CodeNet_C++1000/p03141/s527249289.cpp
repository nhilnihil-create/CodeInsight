#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const ll MAX_N = 1e5 + 5;
ll n, ans;
ll A[MAX_N];
ll B[MAX_N];
vector <ll> v;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
		ans -= B[i];
		v.push_back(A[i] + B[i]);
	}

	sort(v.begin(), v.end());
	for (ll i = n - 1; 0 <= i; i -= 2)
		ans += v[i];

	cout << ans << endl;
	return 0;
}