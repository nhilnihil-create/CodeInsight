#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n,m,d;
	cin >> n >> m >> d;
	double ans = 1.0 * 2 * ( n - d ) * ( m - 1 ) / n / n;
	if(d==0) ans /= 2.0;
	cout<<setprecision(12)<<ans<<endl;
	return 0;
}