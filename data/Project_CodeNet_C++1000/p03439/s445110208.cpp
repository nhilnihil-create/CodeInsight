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
#include <unordered_map>
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
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef vector< vector<int> > mat;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

const double EPS = 1e-9;

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int l = 0, r = N;
	char lc, lr;

	cout << 0 << endl;
	string s;
	cin >> s;

	if (s[0] == 'V')return 0;

	lc = lr = s[0];

	rep(i, 0, 19)
	{
		int mid = (l + r) / 2;
		cout << mid << endl;
		cin >> s;
		if (s[0] == 'V')break;
		if (lc == s[0])
		{
			if ((mid - l) % 2 == 0)
			{
				l = mid;
				lc = s[0];
			}
			else
			{
				r = mid;
				lr = s[0];
			}
		}
		else
		{
			if ((mid - l) % 2 == 1)
			{
				l = mid;
				lc = s[0];
			}
			else
			{
				r = mid;
				lr = s[0];
			}
		}
	}

	return 0;
}