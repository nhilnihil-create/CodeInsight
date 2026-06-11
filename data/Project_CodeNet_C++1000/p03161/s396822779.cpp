#include<iostream>
using namespace std;

#define ll long long 

ll n,k;
ll a[100005];
ll dp[100005];
const ll Inf = 1e10;
ll MinCostToReachFromNToZero(ll N){
	if(N <= 0)return 0;
  	if(dp[N] != -1)return dp[N];
  	ll ans = Inf;
  	for(int i = 1; i <= k; i++){
    	if(N - i >= 0){
        	ans = min(ans,(abs(a[N]-a[N-i]) + MinCostToReachFromNToZero(N-i)));
        }
    }
  	//cout << N << " " << ans << "\n";
  	return dp[N] = ans;
}
int main(){
	cin >> n >> k;
  	for(ll i = 0; i < n; i++)cin >> a[i];
  	for(ll i = 0; i < n+1; i++)dp[i] = -1;
  
	cout << MinCostToReachFromNToZero(n-1) << endl;
  	return 0;
}
