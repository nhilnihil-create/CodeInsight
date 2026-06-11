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

int N;
int D[100010],OD[100010],OP[100010];
int SSZ[100010];
vector<pii> ANS;
int CD[100010];
vector<int> G[100010];

void dfs(int idx,int par,int cnt)
{
	CD[idx]=cnt;
	for(auto e:G[idx])
	{
		if(e==par)continue;
		dfs(e,idx,cnt+1);
	}
}

bool func()
{
	dfs(0,-1,0);
	int t=0;
	rep(i,0,N)
	{
		t+=CD[i];
	}
	return t==D[0];
}
 
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>N;
	rep(i,0,N)
	{
		cin>>OD[i];
		D[i]=OD[i];
	}

	sort(D,D+N);

	rep(i,0,N)
	{
		int op=lower_bound(D,D+N,OD[i])-D;
		OP[op]=i;
	}

	bool ok=true;
	rrep(i,1,N)
	{
		SSZ[i]++;
		int sd=D[i]-(N-SSZ[i]*2);
		int idx=lower_bound(D,D+N,sd)-D;
		if(idx==N||idx==i||D[idx]!=sd)
		{
			ok=false;
			break;
		}
		SSZ[idx]+=SSZ[i];
		ANS.push_back(mp(idx,i));
		G[idx].push_back(i);
		G[i].push_back(idx);
	}

	if(!ok||!func())
	{
		cout<<-1<<endl;
		return 0;
	}

	for(auto p:ANS)
	{
		cout<<OP[p.first]+1<<" "<<OP[p.second]+1<<endl;
	}
	
	return 0;
}