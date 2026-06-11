#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

signed main() {
	int a,b,c,x;
	cin>>a>>b>>c>>x;
	int ans = a+b+c+max({a,b,c})*((1<<x)-1);
	cout << ans << endl;
}
