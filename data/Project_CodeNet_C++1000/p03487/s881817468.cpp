#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll a[100005];
int main() {
	int n;
	cin >> n;
	map<ll, ll>mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	ll ans = 0;
	for (auto id : mp) {
		if (id.first > id.second) {
			ans += id.second;
		}
		else if (id.first < id.second) {
			ans += id.second - id.first;
		}
	}
	cout << ans << endl;
	return 0;
}