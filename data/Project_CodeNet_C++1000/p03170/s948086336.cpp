#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define mod 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define F first
//#define S second
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE    
    freopen("input.txt", "r", stdin);     
    freopen("output.txt", "w", stdout);
#endif
int n,k;
cin>>n>>k;
int arr[n];
rep(i,n){
	cin>>arr[i];
}
int dp[k+1];
memset(dp,0,sizeof(dp));
for(int i = 1;i<=k;i++){
	for(int j = 0;j<n;j++){
		if(arr[j]<=i && !dp[i])
			dp[i] = 1-dp[i-arr[j]];
		if(dp[i])
			break;
	}

}
string s = dp[k]?"First":"Second";
cout<<s;






#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#endif

return 0;
}