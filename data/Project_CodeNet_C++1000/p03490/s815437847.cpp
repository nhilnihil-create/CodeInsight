#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <functional>

using namespace std;

typedef long long int ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

//! [Xのi番目までの和で][kが作れるか]
bool dpx[4000][8000];
bool dpy[4000][8000];

int main()
{
	string S;
	cin >> S;
	int x, y;
	cin >> x >> y;
	vector<int> X, Y;
	int n = 0;
	int t = 0;
	REP(i, S.length())
	{
		if (S[i] == 'F')
		{
			n++;
			if (i != S.length() - 1)
			{
				continue;
			}
		}
		t++;
		if (t == 1)
		{
			x -= n;
			n = 0;
			continue;
		}

		if (n != 0)
		{
			if (t % 2 == 1)
			{
				X.push_back(n);
			}
			else
			{
				Y.push_back(n);
			}
		}
		n = 0;
	}

	memset(dpx, 0, sizeof(dpx));
	memset(dpy, 0, sizeof(dpy));
	dpx[0][0] = dpy[0][0] = true;

	ll max = 0;
	FOR(i, X.size() + 1, 1)
	{
		ll m = max;
		REP(j, max + 1)
		{
			if (dpx[i - 1][j])
			{
				m = std::max(m, std::max(j + X[i - 1], abs(j - X[i - 1])));
				dpx[i][j + X[i - 1]] = dpx[i][abs(j - X[i - 1])] = true;
			}
		}
		max = std::max(max, m);
	}
	max = 0;
	FOR(i, Y.size() + 1, 1)
	{
		ll m = max;
		REP(j, max + 1)
		{
			if (dpy[i - 1][j])
			{
				m = std::max(m, std::max(j + Y[i - 1], abs(j - Y[i - 1])));
				dpy[i][j + Y[i - 1]] = dpy[i][abs(j - Y[i - 1])] = true;
			}
		}
		max = std::max(max, m);
	}

	if (dpx[X.size()][abs(x)] && dpy[Y.size()][abs(y)])
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}