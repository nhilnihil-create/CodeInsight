#include<iostream>
using namespace std;

#define ll long long 

ll n;
ll a[100005];
ll dp[100005];
const ll Inf = 1e10;

ll MinCostToReachFromNToZero(ll N){
  	if(dp[N] != -1)return dp[N];
	if(N <= 0) return 0;
  	ll ans = abs(a[N] - a[N-1]) + MinCostToReachFromNToZero(N-1);
    if(N-2 >= 0){
  		ll ans2 = abs(a[N] - a[N-2]) + MinCostToReachFromNToZero(N-2);
  		ans = min(ans,ans2);
    }
    //cout << N << " " << ans << endl;
  	return dp[N] = ans;
}

int main(){
	cin >> n;
  	for(ll i = 0; i < n; i++)cin >> a[i];
  	for(ll i = 0; i < n+1; i++)dp[i] = -1;
  
	cout << MinCostToReachFromNToZero(n-1) << endl;
  	return 0;
}
