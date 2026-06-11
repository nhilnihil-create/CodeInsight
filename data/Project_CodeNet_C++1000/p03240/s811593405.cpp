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
//#define int long long
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
	vector<int>x, y, h;
	x = y = h = vector<int>(n);
	rep(i, n) {
		cin >> x[i] >> y[i] >> h[i];
	}
	bool findtop = false;
	rep(i, 101) {
		if (findtop)break;
		rep(j,101) {
			if (findtop)break;
			int maxheight = 0;
			int maxk = 0;
			rep(k, n) {
				if (h[k] > 0) {
					maxheight = h[k] + abs(x[k] - i) + abs(y[k] - j);
					maxk = k;
					break;
				}
			}
			rep(k, n) {
				if (h[k] != max((maxheight - abs(x[k] - i) - abs(y[k] - j)), 0))break;
				if (k == n - 1) {
					cout << i <<" "<< j<<" "<<  h[maxk] + abs(x[maxk] - i) + abs(y[maxk] - j);
					findtop = true;
				}
			}
		}
	}
}