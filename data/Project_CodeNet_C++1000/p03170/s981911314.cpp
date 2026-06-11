#include<bits/stdc++.h>
using namespace std;
#define int long long
template <class Q>
void clearQueue(Q & q) {
    q = Q();
}
void solve(){
	int dp[100005];
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int& x:a){
        cin>>x;
    }
    dp[0]=0;
    for(int i=1;i<=k;i++){
        dp[i]=0;
        for(int j=0;j<n;j++){
            if(i-a[j]>=0&&dp[i-a[j]]==0) dp[i]=1;
        }
    }
    if(dp[k]==1) cout<<"First";
    else cout<<"Second";
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL); 
	int T=1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
