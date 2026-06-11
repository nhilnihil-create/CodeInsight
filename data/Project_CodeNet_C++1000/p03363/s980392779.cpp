#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main()
{
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<ll> s(n);
	s[0] = a[0];
	for (int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];

	map<ll, ll> nums;
	nums[0] = 1;
	for (int i = 0; i < n; i++) {
		if (nums.count(s[i])) nums[s[i]]++;
		else nums[s[i]] = 1;
	}

	ll res = 0;
	for (const auto& item : nums) {
		res += item.second * (item.second - 1) / 2;
	}
	cout << res << endl;
}
