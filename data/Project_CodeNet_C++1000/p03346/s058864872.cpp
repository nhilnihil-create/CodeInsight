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
	int n; cin >> n;
	vector<int> q(n);
	rep(i, n)
	{
		int p; cin >> p;
		q[p - 1] = i;
	}
	int res = 1;
	for (int i = 0; i < n - 1; ++i)
	{
		int cnt = 1;
		int tmp = q[i];
		while (i+1 < n&&tmp < q[i+1])
		{
			++cnt;
			tmp = q[i + 1];
			++i;
		}
		res = max(res, cnt);
	}
	cout << n - res << endl;
}