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
	int f[101][10];
	int p[101][11];
	rep(i, n) {
		rep(j, 10) {
			cin >> f[i][j];
		}
	}
	rep(i, n) {
		rep(j, 11) {
			cin >> p[i][j];
		}
	}
	int ret = -INF;
	for (int bit = 0; bit < (1 << 10); ++bit) {
		vector<int> open;
		vector<int>same(n, 0);//i件目のお店ではsame[i]個の時間帯で同時に営業している
		rep(i, 10) {
			if (bit & (1 << i)) {
				open.push_back(i);
			}
		}
		if (open.size() == 0)continue;
		rep(i, open.size()) {
			rep(j, n) {
				if (f[j][open[i]] == 1)same[j]++;
			}
		}
		int profit = 0;
		rep(i, n) {
			profit += p[i][same[i]];
		}
		ret = max(ret, profit);
	}
	print(ret);
}