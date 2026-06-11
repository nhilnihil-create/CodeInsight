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

struct Edge
{
	int s, t, cost;
	Edge(int s, int t, int cost) :s(s), t(t), cost(cost) {}
	Edge() :Edge(-1, -1, -1) {}
};

vector<Edge> G[100010];
int d[100010];
int V;

void shortest_path(int s)
{
	rep(i, 0, V)d[i] = INF;
	d[s] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(mp(0, s));

	while (!pq.empty())
	{
		pii p = pq.top(); pq.pop();
		if (d[p.second] < p.first)
		{
			continue;
		}
		for (auto& e : G[p.second])
		{
			if (d[e.t] > d[e.s] + e.cost)
			{
				d[e.t] = d[e.s] + e.cost;
				pq.push(mp(d[e.t], e.t));
			}
		}
	}
}

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> V;

	rep(i, 0, V)
	{
		G[i].push_back(Edge(i, (i + 1) % V, 1));
		G[i].push_back(Edge(i, (i * 10) % V, 0));
	}

	shortest_path(1);

	cout << d[0] + 1 << endl;

	return 0;
}