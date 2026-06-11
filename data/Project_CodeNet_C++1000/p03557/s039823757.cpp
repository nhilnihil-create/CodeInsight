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
	
;	vector<int>smallera(n, 0);//b[i]より小さいaの個数
	vector<int>smallerb(n, 0);//c[i]より小さいbの個数
	int itera = 0;
	rep(i, n) {
		if (i != 0)smallera[i] = smallera[i - 1];
		while (itera<=n-1 && b[i] > a[itera]) {
			smallera[i]++;
			itera++;
		}
	}
	int iterb = 0;
	rep(i, n) {
		if (i != 0)smallerb[i] = smallerb[i - 1];
		while (iterb<=n-1 && c[i] > b[iterb]) {
			smallerb[i]+=smallera[iterb];
			iterb++;
		}
	}
	int ret = 0;
	rep(i, n) {
		ret += smallerb[i];
	}
	print(ret);
}