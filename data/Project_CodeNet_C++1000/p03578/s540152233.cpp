#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
	ll N;
	cin >> N;
	map<ll, ll> m;
	string ans = "YES";
	for (ll i = 0; i < N; i++)
	{
		ll temp;
		cin >> temp;
		m[temp]++;
	}
	ll M;
	cin >> M;
	for (ll i = 0; i < M; i++)
	{
		ll temp;
		cin >> temp;
		if (m[temp] == 0) {
			ans = "NO";
			break;
		}
		--m[temp];
	}
	cout << ans;
	return 0;
}