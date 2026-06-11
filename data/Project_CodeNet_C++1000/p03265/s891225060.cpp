#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long

signed main() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	int v1 = c - a, v2 = d - b;
	cout << c - v2 << ' ' << d + v1 << ' ' << a - v2 << ' ' << b + v1 << endl;
}