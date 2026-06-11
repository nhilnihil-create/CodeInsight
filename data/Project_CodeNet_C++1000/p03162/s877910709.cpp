#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cmath>
#include<numeric>
#include<iomanip>
#include<functional>
#include<cstdlib>
#include<queue>
#include<deque>
#include <iterator>     // std::back_inserter
const double PI = acos(-1);
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
using ll =long long;
const int mod = 1000000007;
const ll inf = 1e18+1;
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

ll gcd(ll a, ll b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
};
//fixed << setprecision(2)
bool  Array_check(ll y, ll x,ll d,ll w) {
	if (x < 0 || x >= w || y<0 || y>=d) {
		return false;
	}
	else {
		return true;
	}
	
}
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
//小文字=大文字+32
int main() {
	
	int n;
	cin >> n;
	vector<vector<int>>a(n, vector<int>(3));
	vector<int>dp(3);
	vector<int>tmp(3);
	rep(i, n) {
		rep(j, 3) {
			cin >> a[i][j];
		}
	}
	dp[0] = a[0][0];
	dp[1] = a[0][1];
	dp[2] = a[0][2];
	tmp = dp;
		//copy(dp.begin(), dp.end(), back_inserter(tmp));
	for (int i = 1; i < n; i++) {
		dp[0] = max(a[i][0] + tmp[1], a[i][0] + tmp[2]);
		dp[1] = max(a[i][1] + tmp[0], a[i][1] + tmp[2]);
		dp[2] = max(a[i][2] + tmp[1], a[i][2] + tmp[0]);
		tmp = dp;
		//copy(dp.begin(), dp.end(), back_inserter(tmp));
	}
	cout << max({ dp[0], dp[1], dp[2] }) << endl;

}
