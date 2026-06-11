#include <iostream>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
const ll MOD = 1000000007;
int a[26];
int main() {
	int n;
	string s;
	cin >> n >> s;
	rep(i, n) a[s[i] - 'a']++;
	ll ans = 1;
	rep(i, 26) ans = ans * (a[i] + 1) % MOD;
	cout << (ans + MOD - 1) % MOD << endl;
	return 0;
}