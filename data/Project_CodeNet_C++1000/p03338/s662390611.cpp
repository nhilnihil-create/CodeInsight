#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	ll count = 0;
	ll ans = -inf;
	for (int i = 0; i < n - 1; i++) {
		count = 0;
		vector<ll>check(1000, inf);
		for (int j = i + 1; j < n; j++) {
			for (int k = 0; k <= i; k++) {
				if (s[k] == s[j] && check[s[k]] == inf) {
					count++;
					check[s[k]] = 1;
				}
			}
		}
		ans = max(ans, count);
	}
	cout << ans << endl;
	return 0;
}


