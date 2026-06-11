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
#include<unordered_map>
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
const int MOD =  (int)1e9 + 7;
const double EPS = 1e-9;

struct ST
{
	vector<int> node;
	int N;

	ST(int sz)
	{
		N = 1;
		while (N < sz)N *= 2;
		node.resize(2 * N - 1, INF);
	}

	ST(int* a, int sz)
	{
		N = 1;
		while (N < sz)N *= 2;
		node.resize(2 * N - 1, INF);

		rep(i, 0, sz)node[N - 1 + i] = a[i];
		rrep(i, 0, N - 1)node[i] = min(node[2 * i + 1], node[2 * i + 2]);
	}

	ST(vector<int> a)
	{
		N = 1;
		while (N < SZ(a))N *= 2;
		node.resize(2 * N - 1, INF);

		rep(i, 0, SZ(a))node[N - 1 + i] = a[i];
		rrep(i, 0, N - 1)node[i] = min(node[2 * i + 1], node[2 * i + 2]);
	}

	void update(int i, int a)
	{
		node[N - 1 + i] = a;
		int k = N - 1 + i;
		while (k > 0)
		{
			k = (k - 1) / 2;
			node[k] = min(node[2 * k + 1], node[2 * k + 2]);
		}
	}

	int query(int a, int b, int k, int l, int r = -1)
	{
		if (r == -1)r = N;
		if (b <= l || r <= a)
		{
			return INF;
		}
		if (a <= l&&r <= b)
		{
			return node[k];
		}
		else
		{
			return min(query(a, b, 2 * k + 1, l, (l + r) / 2), query(a, b, 2 * k + 2, (l + r) / 2, r));
		}
	}
};

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin>>N;
	vector<int> H(N),A(N);
	rep(i,0,N)
	{
		cin>>H[i];
		H[i]--;
	}
	rep(i,0,N)cin>>A[i];
	ST st(N);
	vector<int> DP(N+1,0);

	rep(i,0,N)
	{
		int s=-st.query(0,H[i],0,0);
		if(s==-INF)s=0;
		DP[i]=s+A[i];
		st.update(H[i],-DP[i]);
	}

	int ans=0;
	rep(i,0,N)chmax(ans,DP[i]);

	cout<<ans<<endl;
	
	return 0;
}