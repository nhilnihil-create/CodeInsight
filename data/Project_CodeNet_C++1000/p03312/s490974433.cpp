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
	vector<ll> sum(n + 1, 0);
	rep(i, n)
	{
		ll a; cin >> a;
		sum[i + 1] = sum[i] + a;
	}
	ll res = 1e18;
	for (int i = 2; i < n - 1; ++i)
	{
		ll p, q, r, s;
		auto it = upper_bound(all(sum), sum[i] / 2);
		p = *it;
		--it;
		if (it != sum.begin() && sum[i] / 2 - *it < p - sum[i] / 2)
		{
			p = *it;
			q = sum[i] - *it;
		}
		else
		{
			++it;
			q = sum[i] - *it;
		}
		it = upper_bound(all(sum), (sum[n] - sum[i]) / 2 + sum[i]);
		if (it == sum.end())
		{
			--it;
			r = *it - sum[i];
			s = sum[n] - r - sum[i];
		}
		else
		{
			r = *it - sum[i];
			--it;
			if ((sum[n] - sum[i]) / 2 - (*it - sum[i]) < r - (sum[n] - sum[i]) / 2)
			{
				r = *it - sum[i];
				s = sum[n] - r - sum[i];
			}
			else
			{
				s = sum[n] - r - sum[i];
			}
			/*cout << "p:" << p << endl;
			cout << "q:" << q << endl;
			cout << "r:" << r << endl;
			cout << "s:" << s << endl;*/
		}
		ll tmp = max({ p,q,r,s }) - min({ p,q,r,s });
		res = min(res, tmp);
	}
	cout << res << endl;
}