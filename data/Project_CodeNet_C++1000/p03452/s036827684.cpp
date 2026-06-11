#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <math.h>

typedef long long int ll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;

using namespace std;

vector<pair<int, int>> D[100005];
bool U[100005];
bool I[100005];
ll x[100005];

bool check(int i)
{
	if (U[i])return true;
	U[i] = true;
	REP(j, D[i].size())
	{
		pair<int, int> n = D[i][j];
		if (I[n.first])
		{
			if (x[n.first] != x[i] + n.second)
			{
				return false;
			}
		}
		I[n.first] = true;
		x[n.first] = x[i] + n.second;

		if (!check(n.first))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int N, M;
	cin >> N >> M;
	REP(i, M)
	{
		int l, r, d;
		cin >> l >> r >> d;
		l--; r--;
		D[l].push_back(pair<int, int>(r, d));
		D[r].push_back(pair<int, int>(l, -d));
	}
	I[0] = true;
	REP(i, N)
	{
		if (!check(i))
		{
			cout << "No" << endl;
			return 0;
		}
	}

	ll max = 0, min = 0;
	REP(i, N)
	{
		if (I[i])
		{
			max = std::max(max, x[i]);
			min = std::min(min, x[i]);
		}
	}
	if (max - min > 1000000000)
	{
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	return 0;
}