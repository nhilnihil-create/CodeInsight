#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
string s;
ll n, a[30];
ll mod = 1e9 + 7;
int main() {
	cin >> n;
	cin >> s;
	for (ll i = 0; i < 26; ++i)a[i] = 1;
	for (ll i = 0; i < n; ++i) {
		++a[s[i] - 'a'];
	}
	ll ans = 1;
	for (int i = 0; i < 26; ++i) {
		ans = (ans * a[i]) % mod;
	}
	cout << ans - 1 << endl;
	return 0;
}