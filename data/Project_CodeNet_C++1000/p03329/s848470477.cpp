#include <bits/stdc++.h>
using namespace std;
static const int INF = 1<<30;
static const int SIZE = 100000+10;

int main(){
    int n;
    cin>>n;
    vector<int> dp(SIZE,INF);
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        
        for(int six=1; six<=i; six *= 6){
            if(i-six < 0) continue;
            dp[i] = min(dp[i],dp[i-six]+1);
        }

        for(int nine=1; nine<=i; nine *= 9){
            if(i-nine < 0) continue;
            dp[i] = min(dp[i],dp[i-nine]+1);
        }
    }

    cout<<dp[n]<<endl;

    return 0;
}

