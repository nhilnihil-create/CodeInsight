#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int n;
int num[3] = {3,5,7};
ll dfs(ll x) {
	if (x > n) return 0;
	map<int,int> a;
	ll m = x;
	while (m > 0)
	{
		a[m%10]++;
		m /= 10;	
	}
	int res = (a[3]&&a[5]&&a[7])? 1 : 0;
	rep(i,3) {
		res += dfs(x*10+num[i]);
	}
	return res;
} 
int main() {
	cin >> n;
	cout << dfs(0) << endl;
	return 0;
}