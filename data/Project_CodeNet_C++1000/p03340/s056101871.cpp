/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <bits/stdc++.h>
#define   int  long long 
#define   vi   vector<int> 
#define   co(x)  cout << x << '\n' 
using namespace std;

inline void solve(){
    int  n, ans = 0 ; 
    cin >> n ; 
    vi  a(n+1) ; 
    for (int i=1;i<=n;i++) cin >> a[i] ; 
    int sum = 0, xr = 0, cnt = 0 ; 
	for (int i=1;i<=n;i++){
		sum += a[i] ; 
		xr = xr^a[i] ; 
		if (xr == sum) cnt++ ; 
		else {
			int cur = cnt ; 
			while (sum != xr){
				sum -= a[i-cnt];
				xr ^= a[i-cnt] ;
				cnt--;
			}
			ans += cur * (cur+1) / 2 ; 
			ans -= cnt * (cnt+1) / 2 ; 
			cnt++; 
		}
	}
	ans += cnt * (cnt+1) / 2 ; 
	co (ans) ; 
}
signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
