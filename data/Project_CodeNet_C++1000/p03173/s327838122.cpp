#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll pref[405]={};

ll dp[405][405]={};

ll sum(ll a[], ll left, ll right){
//	ll ans=0;
//	for(ll i=left; i<=right; i++)
//		ans+=a[i];
//	return ans;
	// store pref at 1 base index
	return pref[right+1]-pref[left];
}

ll solve(ll a[], int left, int right){
	if(left >= right) return 0;
	
	if(dp[left][right] != -1)
		return dp[left][right];
	
	ll ans = 1e18+1;
	
	for(int k=left; k<=right-1; k++){
		ans=min(ans, solve(a, left, k) + solve(a, k+1, right) + sum(a, left, right) );
	}
	
	return dp[left][right] = ans;	
}

void solve(){
	int n;
	cin >> n;
	
	ll a[n]={};
	
	for(int i=0; i<n; i++)	
		cin >> a[i];
	
	memset(pref, 0, sizeof pref);
	
	pref[0]=0;
	for(int i=1; i<=n; i++){
		pref[i]=pref[i-1]+a[i-1];
	}
	
	// MCM
	memset(dp, -1, sizeof dp);
	ll ans = solve(a, 0, n-1);
	
	cout << ans << "\n";	
}

int main(){
	solve();
}
