/*
author : seryu
title : contest
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

int dx[] = {-1, 0, 1, 0};
int dy[] = { 0,-1, 0, 1};

void solve()
{
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	rep(i, h)rep(j, w)
	{
		if(s[i][j] == '.')continue;
		bool ok = false;
		rep(k, 4)
		{
			int ny = i+dy[k]; 
			int nx = j+dx[k]; 
			if(0 <= ny && ny < h &&
			0 <= nx && nx < w && s[ny][nx] == '#')ok = true;
		}
		if(!ok)
		{
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
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
