#include <bits/stdc++.h>


using namespace std;

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()


unordered_map<ll,ll> dp;
ll cal(int n) {
	if(n==0) return 2;
	else if(n==1) return 1;
	else if(dp.count(n)) return dp[n];
	else {
		dp[n]=cal(n-1)+cal(n-2);
	}
	return dp[n];
}
void go(){
	ll n;cin>>n;
	//dp[0]=2;
	//dp[1]=1;
	//for(int i=2;i<=n;i++) {
		//dp[i]=dp[i-1]+dp[i-2];
	//}
	//cout << dp[n];
	ll ans=cal(n);
	cout << ans;
}
int main(){
   
   fastio();
   cin.tie(0);
   cout.tie(0);

   go();

   return 0;
}


