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

template<class T1> bool chmax(T1 &a, const T1 &b) { if (a < b) { a = b; return true; } return false; }
template<class T1> bool chmin(T1 &a, const T1 &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD =  (int)1e9 + 7;
const double EPS = 1e-9;

struct Cube
{
	int w,s,v;
	Cube(int w,int s,int v):w(w),s(s),v(v){}
	Cube():Cube(0,0,0){}
	bool operator<(const Cube& other)const
	{
		return w+s<other.w+other.s;
	}
};

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin>>N;
	vector<Cube> C(N);
	rep(i,0,N)cin>>C[i].w>>C[i].s>>C[i].v;

	sort(all(C));
	vector<int> DP(20010,0);

	rep(i,0,N)
	{
		rrep(j,0,200010)
		{
			if(j>=C[i].w&&j-C[i].w<=C[i].s)
			{
				chmax(DP[j],DP[j-C[i].w]+C[i].v);
			}
		}
	}

	int ans=0;
	rep(i,0,20010)chmax(ans,DP[i]);

	cout<<ans<<endl;

	return 0;
}