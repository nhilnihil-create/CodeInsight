#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#define ll long long
#define Inf 1000000000
#define MAXN 100000
using namespace std;



int mask[222222];
ll dp[222222];

int main() {
    string S;
    cin>>S;
    
    mask[0]=0;
    for(int i=0;i<S.size();i++) {
        mask[i+1]=mask[i];
        mask[i+1] ^= (1<<(S[i]-'a'));
    }
    
    map<int,ll> mask_to_best;
    mask_to_best[0]=0;
    int L=S.size();
    dp[0]=0;
    for(int i=1;i<=L;i++) {
        dp[i]=Inf;
        if (mask_to_best.find(mask[i]) != mask_to_best.end()) {
            dp[i]=min(dp[i], 1+mask_to_best[mask[i]]);
        }
        
        // mask[i]
        for(int c=0;c<26;c++) {
            int rmask = (mask[i]^(1<<c));
            if (mask_to_best.find(rmask) != mask_to_best.end()) {
                dp[i]=min(dp[i], 1+mask_to_best[rmask]);
            }
        }
        if (mask_to_best.find(mask[i]) == mask_to_best.end() || mask_to_best[mask[i]] > dp[i]) {
            mask_to_best[mask[i]]=dp[i];
        }
    }
    
    cout << dp[L] << endl;
    
}