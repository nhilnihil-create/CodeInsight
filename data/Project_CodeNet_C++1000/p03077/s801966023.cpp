// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long long n;

	vector<long long> v(5);

	cin >> n;
	for(int i = 0; i < 5; i++) cin >> v[i];

	long long mn = *min_element(v.begin(), v.end());

	long long ans = 5;

	ans += (n+mn-1)/mn - 1;

	cout << ans;


	return 0;
}
