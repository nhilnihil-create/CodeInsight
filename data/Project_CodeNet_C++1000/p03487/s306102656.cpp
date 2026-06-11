#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll a[100005];
int main() {
	int n;
	cin >> n;
	map<int, int>mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	ll ans = 0;
	for (auto p : mp) {
		int index = p.first;
		int nakami = p.second;
		if (index <= nakami) {
			ans += nakami - index;
		}
		else {
			ans += nakami;
		}
	}
	cout << ans << endl;
	return 0;
}