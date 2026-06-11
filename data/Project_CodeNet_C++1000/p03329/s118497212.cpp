#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

#define chmin(x,y) x=min(x,y)

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,100000);
    dp[0]=0;
    for(int i=1; i<=n; i++){
        int power;

        chmin(dp[i],dp[i-1]+1);
  
        power = 6;
        while(power <= i){
            chmin(dp[i],dp[i-power]+1);
            power *= 6;
        }
        
        power = 9;
        while(power <= i){
            chmin(dp[i],dp[i-power]+1);
            power *= 9;
        }
    }
    cout << dp[n] << endl;

    return 0;
}