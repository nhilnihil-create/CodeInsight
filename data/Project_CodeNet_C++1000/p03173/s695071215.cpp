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

ll dp[401][401];
ll topDown(vector<ll>&arr,vector<ll>&pref, int l, int r){
	// if(l>r) return 0;
	// cout<<l<<" "<<r<<endl;
	if(dp[l][r]>-1) return dp[l][r];
	if(r-l==1) return dp[l][r] =  arr[l]+arr[r];
	if(r==l) return dp[l][r] = 0;
	ll ans = 1e18 + 5;
	for(int i=l;i<r;i++){
		ans = min(ans, topDown(arr,pref,l,i) + topDown(arr,pref,i+1,r) + pref[r]-pref[l-1]);
	}
	dp[l][r] = ans;
	return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<ll>arr(n+1),pref(n+1,0);
    for(int i=1;i<=n;i++) cin>>arr[i];
    pref[1] = arr[1];
    for(int i=2;i<=n;i++) pref[i]=pref[i-1] + arr[i];
    memset(dp,-1,sizeof(dp));
    ll ans = topDown(arr,pref,1,n);
    t1(ans)
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