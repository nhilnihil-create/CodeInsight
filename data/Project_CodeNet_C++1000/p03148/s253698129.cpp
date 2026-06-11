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

int N, K;
pii S[100010];
int tn[100010];
priority_queue<pii, vector<pii>, greater<pii>> pq;

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int t, d;
	cin >> N >> K;
	rep(i, 0, N)
	{
		cin >> S[i].second >> S[i].first;
	}

	sort(S, S + N);

	int res = 0;
	set<int> tns;
	rrep(i, N - K, N)
	{
		res += S[i].first;
		pq.push(S[i]);
		tn[S[i].second]++;
		tns.insert(S[i].second);
	}
	int tnss = tns.size();

	res += tnss * tnss;

	int ans = res;

	rrep(i, 0, N - K)
	{
		if (tn[S[i].second] == 0)
		{
			while (!pq.empty())
			{
				auto p = pq.top();
				pq.pop();
				if (tn[p.second] > 1)
				{
					tn[p.second]--;
					tn[S[i].second]++;
					tnss++;
					res -= p.first - S[i].first;
					res += tnss * tnss - (tnss - 1)*(tnss - 1);
					chmax(ans, res);
					break;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}