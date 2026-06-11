/*
author : seryu
title : AGC021A_"Digit Sum2"
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
	if(n == 1)
	{
		cout << s[0] << endl;
		return;
	}
	int last = -1;
	rep(i, n)
	{
		if(s[i] != '9')
		{
			chmax(last, i);
			break;
		}
	}

	if(last < 0)
	{
		cout << n*9 << endl;
	}
	else if(last > 0)
	{
		cout << n*9-1 << endl;
	}
	else
	{
		bool flag = false;
		reps(i,n-1)if(s[i] != '9')flag = true;
		int ans = flag ? int(s[0]-'0')-1+(n-1)*9:int(s[0]-'0')+(n-1)*9;
		cout << ans << endl;
	}
	
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
