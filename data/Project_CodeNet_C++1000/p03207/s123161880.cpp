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
	ll n,ans=0;
	string s;

	cin >> n;

	vector<ll> a(n);

	forll(i, 0, n)
		cin >> a[i];

	sort(a.begin(), a.end(), greater<ll>());

	ans+=a[0] / 2;

	forll(i, 1, n)
	{
		ans += a[i];
	}

	cout << ans;
}