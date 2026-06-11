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
	vector<int>a(n);
	vector<int>b(n);
	vector<int>c(n);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
	}
	rep(i, n) {
		cin >> c[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	
	int ret = 0;
	rep(i, n) {
		auto itera = lower_bound(a.begin(), a.end(), b[i]);
		auto iterc = upper_bound(c.begin(), c.end(), b[i]);
		int smallera = itera - a.begin();
		int smallerc = iterc - c.begin();
		ret += smallera * (n-smallerc);
	}
	print(ret);
}