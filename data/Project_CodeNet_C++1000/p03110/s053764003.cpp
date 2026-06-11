#include <iostream>
#include <cstdio>
#include <bitset>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

//fixed << setprecision(8)

using namespace std;

#define ll long long
#define vec vector
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)

int main()
{
	ll n,buf=0;
	double ans=0;
	string s;

	cin >> n;

	vector<pair<double, string>> a(n);

	forll(i, 0, n)
		cin >> a[i].first >> a[i].second;

	forll(i, 0, n)
	{
		if (a[i].second == "JPY")
			ans += a[i].first;
		else
			ans += a[i].first * 380000;
	}

	cout << fixed << setprecision(6) << ans;
}