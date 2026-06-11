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
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n; cin >> n;
	int res = 0;
	vector<int> a(n); rep(i, n)cin >> a[i];
	rep(i, n - 1)
	{
		int cnt = 1;
		while (i < n - 1 && a[i] == a[i + 1])
		{
			++cnt;
			++i;
		}
		res += cnt / 2;
	}
	cout << res << endl;
}