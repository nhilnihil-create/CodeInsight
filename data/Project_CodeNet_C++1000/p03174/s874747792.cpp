#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<ll,pair<ll,char>>
#define sorted(a_1) sort(a_1.begin(),a_1.end())
#define rsorted(a_1) sort(a_1.rbegin(),a_1.rend())
#define t1(a_1) cout<<a_1<<endl;
#define t2(a_1) for(auto it_test : a_1) cout<<it_test<<" ";
#define MOD 1000000007

ll dp[1<<22];
ll topDown(vector<vector<int>>&arr, int n,int man, ll mask){
	ll ans = 0;
	if(man==n) return 1;
	if(dp[mask]>-1){ return dp[mask]%MOD;}
	for(int i=1;i<=n;i++){
		int k = mask & 1<<i;
		if(arr[man][i-1] && k==0){
			ll p = mask | 1<<i;
			ans += topDown(arr,n,man+1,p);
			ans%=MOD;
		}
	}  
	dp[mask] = ans;
	return ans;
}
// 2^21 =2 * 10^6
void solve(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n+1,vector<int>(n+1));
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>arr[i][j];
    	}
    }
    memset(dp,-1,sizeof(dp));
    ll ans = topDown(arr,n,0,1LL);
    t1(ans%MOD);
    // for(int i=0;i<n;i++){
    // 	for(int j=0;j<=2^n;j++){

    // 	}
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--){
        solve();
    }

return 0;
}