#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>

using namespace std;
typedef long long  ll;

const ll mod = 1000000007;

int main()
{
	ll N;
	cin >> N;
	string str;
	cin >> str;
	map<char, ll> mp;
	for (size_t i = 0; i < str.size(); i++)
	{
		mp[str[i]]++;
	}
	ll ans = 1;
	for (char i = 'a'; i < 'z' + 1; i++)
	{
		ans *= mp[i] + 1;
		ans %= mod;
	}
	cout << (ans  + mod - 1) % mod << endl;
	return 0;
}