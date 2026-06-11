#pragma region
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#include <cstdint>
#include <cstdlib>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n, k; cin >> n >> k;
	vector<pair<ll, int>> sushi(n);
	vector<bool> chosen(n + 1);
	rep(i, n)
	{
		int t; ll d; cin >> t >> d;
		sushi[i] = make_pair(d, t);
	}
	sort(all(sushi), greater<pair<ll, int>>());
	ll res = 0;
	ll x = 0;
	vector<ll> removeCandidate, addCandidate;
	rep(i, k)
	{
		int t = sushi[i].second;
		ll d = sushi[i].first;
		res += d;
		if (!chosen[t])
		{
			chosen[t] = true;
			++x;
		}
		else removeCandidate.push_back(d);
	}
	res += x * x;
	for (int i = k; i < n; ++i)
	{
		int t = sushi[i].second;
		ll d = sushi[i].first;
		if (!chosen[t])
		{
			addCandidate.push_back(d);
			chosen[t] = true;
		}
	}
	sort(all(removeCandidate));
	sort(all(addCandidate), greater<ll>());
	ll can = res;
	for (int i = 0; i < min(removeCandidate.size(), addCandidate.size()); ++i)
	{
		can -= removeCandidate[i];
		can += addCandidate[i];
		can -= x * x;
		++x;
		can += x * x;
		res = max(res, can);
	}
	cout << res << endl;
}