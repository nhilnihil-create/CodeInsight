#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
typedef pair<int, int> P;

signed main() {
	int a, b, c; cin >> a >> b >> c;
	if (a < c&&c < b)puts("Yes");
	else if (b < c&&c < a)puts("Yes");
	else puts("No");
}