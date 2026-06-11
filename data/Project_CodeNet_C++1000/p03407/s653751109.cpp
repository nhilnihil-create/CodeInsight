#include"bits/stdc++.h"
#include<cassert>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const int mod = 1000000007;
const int inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<int, P>PP;

signed main() {
	int a, b, c; cin >> a >> b >> c;
	if (a + b >= c)puts("Yes");
	else puts("No");
}