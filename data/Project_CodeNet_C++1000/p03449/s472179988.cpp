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
	int n;
	cin >> n;
	int a[2][101];
	rep(i, 2) {
		rep(j, n) {
			cin >> a[i][j];
		}
	}
	int b[2][101];
	b[0][0] = a[0][0];
	b[1][n - 1] = a[1][n - 1];
	rep1(i, n) {
		b[0][i] = b[0][i - 1] + a[0][i];//0からiまでを計算したもの
		b[1][n - 1 - i] = b[1][n - i] + a[1][n - 1 - i];//n-1からiまでを計算したもの
	}
	int ret = 0;
	rep(i, n) {
		ret = max(ret, b[0][i] + b[1][i]);
	}
	print(ret);
}