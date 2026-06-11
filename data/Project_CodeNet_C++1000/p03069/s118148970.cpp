#pragma region
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
	string s; cin >> s;
	vector<int> sum(n + 1);
	sum[0] = 0;
	rep(i, n)
	{
		sum[i + 1] = sum[i];
		if (s[i] == '#')++sum[i + 1];
	}
	int res = 1e9;
	rep(i, n + 1)
	{
		res = min(res, sum[i] + n - i - sum[n] + sum[i]);
	}
	cout << res << endl;
}