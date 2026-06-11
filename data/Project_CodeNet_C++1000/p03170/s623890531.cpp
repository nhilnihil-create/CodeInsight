#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5+5;

ll n,k,arr[N];

ll dp[N][2];

bool solve(ll kk, bool first){
    if(kk < arr[0] )    
        return !first;
        
    if(dp[kk][first] != -1) return dp[kk][first];
    
    bool ans = false;
    
    for(ll i=0;i<n;i++){
        if(arr[i] > kk) break;
        bool x = solve(kk-arr[i], !first);
        if(!first && !x){
            ans = false;
            break;
        }
        ans = ans || x;
    }
    
    return dp[kk][first] = ans;
}

int main() {
    scanf("%lld%lld",&n,&k);
    
    for(ll i=0;i<n;i++){
        scanf("%lld",arr+i);
    }
    
    memset(dp, -1, sizeof(dp));
    
    if(solve(k, 1)) printf("First");
    else printf("Second");
    
    return 0;
}