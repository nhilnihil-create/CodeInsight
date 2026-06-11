#include<iostream>
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
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	map<int, int>mp;
	for (int i = 0; i < n; i++) {
		mp[a[i]]++;
	}

	int ans = 0;
	for (auto id : mp) {
		int x = id.first;
		int n = id.second;
		
		if (n < x)ans += n;
		else ans += n - x;
	}
	cout << ans << endl;
	return 0;
}