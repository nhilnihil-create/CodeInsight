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


int main()
{
	int m, k; cin >> m >> k;
	if (m == 0)
	{
		if (k == 0)cout << "0 0" << endl;
		else cout << -1 << endl;
	}
	else if (m == 1)
	{
		if (k == 0)cout << "1 0 0 1" << endl;
		else cout << -1 << endl;
	}
	else
	{
		if (pow(2, m) - 1 < k)cout << -1 << endl;
		else
		{
			vector<int> res;
			rep(i, pow(2, m))
			{
				if (i == k)continue;
				res.push_back(i);
			}
			cout << k << " ";
			for (int a : res)cout << a << " ";
			cout << k << " ";
			reverse(all(res));
			for (int a : res)cout << a << " ";
		}
	}
}