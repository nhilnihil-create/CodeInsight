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
	int n; cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n)cin >> a[i];
	rep(i, n)cin >> b[i];
	ll mx = 0;
	ll sumA = 0, sumB = 0;
	rep(i, n)
	{
		sumA += a[i];
		sumB += b[i];
		if (a[i] < b[i])mx += (b[i] - a[i] + 1) / 2;
	}
	if (mx <= sumB - sumA)cout << "Yes" << endl;
	else cout << "No" << endl;
}
