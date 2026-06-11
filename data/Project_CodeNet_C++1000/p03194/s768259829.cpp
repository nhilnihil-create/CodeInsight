#define _USE_MATH_DEFINES
#include<cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include<iomanip>

using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

typedef long long ll;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector<vector<int>> mat;
//typedef unsigned int uint;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, P;
	cin >> N >> P;

	int t = P;
	vector<pair<int,int>> prime;
	for (int i = 2; i <= (int)sqrt(P); i += (i == 2 ? 1 : 2))
	{
		if (t%i == 0)
		{
			prime.push_back(mp(i, 0));
		}
		while (t%i == 0)
		{

			prime.back().second++;
			t /= i;
		}
	}
	if (t != 1)
	{
		prime.push_back(mp(t, 1));
	}

	int ans = 1;
	rrep(i, 0, SZ(prime))
	{
		ans *= pow(prime[i].first, prime[i].second / N);
	}

	cout << ans << endl;

	return 0;
}