#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7; //1000000007で割った余りを聞かれたら使う
int main()
{
	int n;
	string s;
	cin >> n >> s;
	map<char, ll> m;
	for (auto c : s) m[c]++;
	// for (int i = 0; i < s.size(); i++) { m[s[i]]++; } と一緒
	ll ans = 1;
	for (auto x : m)
	{
		ans *= (x.second + 1);
		ans %= MOD;
	}
	ans--; //空文字列の分の1を引く
	cout << ans << endl;
	return 0;
}