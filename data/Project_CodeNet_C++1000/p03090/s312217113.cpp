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
	int m = 0;
	vector<pair<int, int>> res;
	if (n % 2 == 1)
	{
		for (int i = 1; i < n; ++i)res.push_back({ i,n });
		--n;
	}
	for (int i = 1; i < n; ++i)for (int j = i + 1; j <= n; ++j)
	{
		if (i + j == n + 1)continue;
		res.push_back({ i,j });
	}
	cout << res.size() << endl;
	for (auto p : res)cout << p.first << " " << p.second << endl;
}