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

int d[10][10];

void Warshall_Floyd() {
	rep(k, 10) {
		rep(i, 10) {
			rep(j, 10) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

signed main(void) {
	int h,w;
	cin >> h >> w;
	rep(i, 10) {
		rep(j, 10) {
			cin >> d[i][j];
		}
	}
	vector<vector<int>>a(h,vector<int>(w));
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
		}
	}
	Warshall_Floyd();
	int ans = 0;
	rep(i, h) {
		rep(j, w) {
			if (a[i][j] != -1) {
				ans += d[a[i][j]][1];
			}
		}
	}
	print(ans);
}