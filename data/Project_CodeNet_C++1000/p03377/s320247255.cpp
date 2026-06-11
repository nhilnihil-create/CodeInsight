#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long

signed main() {
	int a, b, x; cin >> a >> b >> x;
	if (a <= x&&x <= a + b)puts("YES");
	else puts("NO");
}