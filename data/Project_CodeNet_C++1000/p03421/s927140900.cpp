#include <bits/stdc++.h>
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimization ("O2")
#pragma GCC target("popcnt")
#pragma GCC target ("avx2")
using namespace std;

int main(){
    int n,inc,dec;
    cin >> n >> inc >> dec;
    int v;
    bool f = false;
    for(v = 0 ; v <= n ; v += 1){
        if(v + (n-v+inc-1)/inc == dec && (n-v >= inc|| inc == 1)){
            f = true;
            break;
        }
    }
    if(!f){
        cout << -1 << endl;
        return 0;
    }
    int ans[n+1];
    for(int i = n , j = 1 ; j <= v ; j += 1 , i -= 1){
        ans[j] = i;
    }
    int curr = 1;
    for(int j = 1 ; j <= n ; j += 1){
        for(int i = max(n-(inc*j)+1,v+1) ; i <= n-(inc*(j-1)) ; i += 1){
            ans[i] = curr;
            curr += 1;
        }
        if(n-(inc*j)+1 <= v){
            break;
        }
    }
    for(int i = 1 ; i <= n ; i += 1){
        cout << ans[i] << " ";
    }cout << endl;
    /*int dp[n+1],inc2=1,dec2=1;
    for(int i = 1 ; i <= n ; i += 1){
        dp[i] = 1;
        for(int j = 1 ; j < i ; j += 1){
            if(ans[j] < ans[i]){
                dp[i] = max(dp[i],dp[j]+1);
                inc2 = max(inc2,dp[i]);
            }
        }
    }
    for(int i = 1 ; i <= n ; i += 1){
        dp[i] = 1;
        for(int j = 1 ; j < i ; j += 1){
            if(ans[j] > ans[i]){
                dp[i] = max(dp[i],dp[j]+1);
                dec2 = max(dec2,dp[i]);
            }
        }
    }
    if(inc2 == inc && dec2 == dec){
        cout << 1 << endl;
        return 0;
    }
    assert(false);*/
}