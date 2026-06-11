#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n;
    cin>>n;
    vector<double> dp(n+1);
    dp[0]=1;
    
    for(int i=0;i<n;i++){
        double p;
        cin>>p;
        for(int j=i+1;j>=0;j--){
            dp[j]=(j>0?dp[j-1]*p:0)+dp[j]*(1-p);
        }
    }
    double ans=0;
    for(int i=(n+1)/2;i<=n;i++) ans+=dp[i];
    cout<<setprecision(10)<<ans;
}

int main() {
	// your code goes here
	//freopen("inptmp0.txt","r",stdin);
	int T;
	
	//cin>>T;
	T=1;
	while(T--){
	    solve();
	}
	return 0;
}
