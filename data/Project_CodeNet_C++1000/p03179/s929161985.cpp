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

struct BIT //0-indexed
{
	vector<int> node;
	int mn;

	BIT(int mn)
	{
		this->mn = mn;
		node.resize(mn + 1, 0);
	}

	void add(int i, int x)
	{
		i++;
		while (i <= mn)
		{
			node[i] += x;
			i += (i&-i);
		}
	}

	int sum(int i)
	{
		i++;
		int res = 0;
		while (i > 0)
		{
			res += node[i];
			i -= (i&-i);
		}
		return res;
	}
};

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	string S;
	vector<BIT> DP;
	cin>>N>>S;
	DP.push_back(BIT(N));
	DP.push_back(BIT(N));

	int tar=1;
	DP[0].add(0,1);

	rep(i,1,N)
	{
		DP[tar]=BIT(N);
		rep(j,0,i+1)
		{
			if(S[i-1]=='<')
			{
				int l=0,r=j-1;
				if(r<l)continue;
				int res=DP[tar^1].sum(r)%MOD;
				DP[tar].add(j,res);
			}
			else
			{
				int l=j,r=i-1;
				if(r<l)continue;
				int res=DP[tar^1].sum(r)%MOD;
				if(0<l)res=(res-(DP[tar^1].sum(l-1)%MOD)+MOD)%MOD;
				DP[tar].add(j,res);
			}
		}
		tar^=1;
	}
	tar^=1;

	cout<<DP[tar].sum(N-1)%MOD<<endl;
	
	return 0;
}