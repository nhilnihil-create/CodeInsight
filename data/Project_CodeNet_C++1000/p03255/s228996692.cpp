/*input
5 1
1 999999997 999999998 999999999 1000000000
*/
#include <bits/stdc++.h>
using namespace std;
long long pref[500005],n, a[500005], x;
__int128 get(int trips){
	__int128 ret = 2*pref[trips] + (n+trips)*x;
	for(int i=trips,now=3;i<500005;i+=trips,now+=2)
		ret += (pref[i] - pref[i-trips])*now;
	return ret;
}
int main(){
	#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	#endif
	cin>>n>>x;
	for(int i=1,x;i<=n;cin>>a[i++]);
	reverse(a+1,a+n+1);
	for(int i=1;i<500005;++i) pref[i] = pref[i-1]+a[i];
	__int128 ans = LLONG_MAX;
	for(int trips = 1; trips <= n; ++trips)
		ans = min(ans,get(trips));
	cout<<(unsigned long long)ans;
}