#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007
using namespace std;
 
void solve(){
    int n;
    cin>>n;
    
    vector<double> dp(n+1);
    double p_heads;
    
    dp[0]=1;
    
    for(int coin=0;coin<n;++coin){
        double p_heads;
        cin>>p_heads;
        
        for(int i=coin+1;i>=0;--i)
            dp[i]=((i==0) ? 0 : dp[i-1]*p_heads) + dp[i]*(1.0-p_heads);
        
    }
    
    double ans=0.0;
    
    for(int heads=0;heads<=n;++heads){
        
        int tails=n-heads;
        
        if(heads>tails)        
            ans+=dp[heads];
    
    }
    
    cout<<setprecision(10)<<fixed<<ans;
}

int main(){
    ios::sync_with_stdio(false);    cin.tie(NULL);  cout.tie(NULL);

    solve(); cout<<endl;
    return 0;
}