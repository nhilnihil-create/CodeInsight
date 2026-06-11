/*
author : seryu
title : AGC029A_"Irreversible operation"
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(all(x), val), x.end())
typedef long long ll;
typedef pair<int, int> P;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
ll MOD = 1000000007;
int INF = 1001001001;

void solve()
{
	string s;
	cin >> s;
	int n = sz(s);
	ll num_w = 0;
	vector<int> pw;
	rep(i, n)
	{
		if(s[i] == 'W')
		{
			num_w++;
			pw.push_back(i+1);
		}
	}
	ll ans = 0;
	if(num_w == 0 || num_w == n)
	{
		cout << 0 << endl;
		return;
	}
	else
	{
		rep(i, sz(pw))ans += pw[i];
		ans -= num_w*(num_w+1)/2;
	}
	cout << ans << endl;
	return;	
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
