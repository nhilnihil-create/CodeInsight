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
int Max = 10000000;
int main()
{
	int n, t; double a; cin >> n >> t >> a;
	vector<double> h(n);
	int ans = 0;
	double Min = Max;
	rep(i, n) {
		cin >> h[i];
		h[i] *= 0.006;
		h[i] = t - h[i];
		double q = abs(h[i] - a);
		Min = min(Min, q);
	}
	rep(i, n) {
		if (Min == abs(h[i] - a))
			ans = i+1;
	}
	cout << ans;
}
