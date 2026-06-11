#include <bits/stdc++.h>
const long long MOD = 1e9+7;
using namespace std;
#define ll long long
#define ar array

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a,b;
	cin >> a >> b;
	int ans = max({a+b,a-b,a*b});
	cout << ans << endl;
	return 0;
}
