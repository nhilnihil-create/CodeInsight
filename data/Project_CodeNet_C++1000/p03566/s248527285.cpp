//#include "bits/stdc++.h"

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
#include<unordered_set>
#include<bitset>
#include<complex>

using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

//typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector< vector<int> > mat;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

double MAXV[40010];
int T[110], V[110];

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int sumt = 0;
	fill(MAXV, MAXV + 40010, (double)INF);
	rep(i, 0, N)
	{
		cin >> T[i];
		T[i] *= 2;
	}
	rep(i, 0, N)
	{
		cin >> V[i];
	}
	rep(i, 0, N)
	{
		rep(j, 1, T[i] + 1)
		{
			chmin(MAXV[sumt + j], (double)V[i]);
		}
		rep(j, 0, sumt + 1)
		{
			chmin(MAXV[j], (double)V[i] + (sumt - j) / 2.0);
		}
		sumt += T[i];
	}

	rep(j, 0, sumt + 1)
	{
		chmin(MAXV[j], (sumt - j) / 2.0);
	}

	double vel = 0.0;
	double ans = 0.0;
	rep(i, 0, sumt)
	{
		double nvel = min(MAXV[i + 1], vel + 0.5);
		ans += (vel + nvel) / 2.0;
		vel = nvel;
	}

	cout << fixed << setprecision(12) << ans/2.0 << endl;

	return 0;
}