#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
//解説
int Max = 10000000;
int main()
{
	int n, m; cin >> n >> m;
	vector<int> x(m);
	int ans = 0;
	rep(i, m) cin >> x[i];
	vector<int> d(m - 1);
	
		sort(x.begin(), x.end());
		rep(i, m - 1) d[i] = x[i + 1] - x[i];
		sort(d.begin(), d.end());
		rep(i, m - n) ans += d[i];
	cout << ans;
}