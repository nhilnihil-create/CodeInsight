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
	vector<int> b(n + 1); rep(i, n)cin >> b[i + 1];
	vector<int> res(n);
	for (int i = n - 1; i >= 0; --i)
	{
		bool ok = false;
		for (int j = b.size() - 1; j > 0; --j)
		{
			if (j == b[j])
			{
				res[i] = j;
				b.erase(b.begin() + j);
				ok = true;
				break;
			}
		}
		if (!ok)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	rep(i, n)cout << res[i] << endl;
}