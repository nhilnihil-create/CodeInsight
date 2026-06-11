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

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ll N, M;
	cin >> N >> M;
	string s, t;
	cin >> s >> t;
	ll lms = N * M / gcd(N, M);
	ll p = lms / N, q = lms / M;
	for (ll i = 0; i < N / q; i++)
	{
		if (s[i * q] != t[i * p])
		{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << lms << endl;
	return 0;
}