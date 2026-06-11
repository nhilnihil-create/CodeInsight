#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}
template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}

signed main(void) {
	int h, w;
	cin >> h >> w;
	char s[51][51];
	rep(i, h) {
		rep(j, w) {
			cin >> s[i][j];
		}
	}
	int xx[] = { 0,1,0,-1 };
	int yy[] = { 1,0,-1,0 };
	rep(i, h) {
		rep(j, w) {
			if (s[i][j] == '.')continue;
			int ok = false;
			rep(k, 4) {
				int ni = i + xx[k];
				int nj = j + yy[k];
				if (ni < 0 || h < ni)continue;
				if (nj < 0 || w < nj)continue;
				if (s[ni][nj] == '#')ok =true;
			}
			if (!ok) {
				print("No");
				return 0;
			}
		}
	}
	print("Yes");
}