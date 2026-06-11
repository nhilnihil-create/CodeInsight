#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<tuple>
#include<string>
typedef unsigned long long ll;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define repm(i,a,b) for(int i=(a);i>(b);i--)
#define F first
#define S second
using namespace std;
const ll INF = 1e12;
const double PI = 3.1415926535897932;
const int i_INF = 2147483647;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
	int n;
	cin >> n;
	vector<char> a(n);
	vector<char> b(n);
	vector<char> c(n);
	rep(i, 0, n)cin >> a[i];
	rep(i, 0, n)cin >> b[i];
	rep(i, 0, n)cin >> c[i];
	int ans = 0;
	rep(i, 0, n) {
		int h = 0;
		if (a[i] == b[i])h++;
		if (a[i] == c[i])h++;
		if (c[i] == b[i])h++;
		if (h == 0)ans += 2;
		else if (h == 1)ans++;
	}
	cout << ans << endl;
	return 0;
}