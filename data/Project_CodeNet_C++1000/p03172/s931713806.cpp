#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN];
int dp_old[MAXN], dp[MAXN], sums[MAXN];
int n, k;
const int MOD = 1e9 + 7;

inline int get_sum(int start, int end){
    if(start == 0)
        return sums[end];
    int ans = sums[end] - sums[start - 1];
    if(ans < 0){
        ans += MOD;
    }
    return ans;
}

inline long long int mod_ans(long long int a, int val){
    if(a >= val)
        return a % val;
    return a;
}

int main(){
    cin >> n >> k;
    
    for(int j = 0; j <= k; ++j){
        dp[j] = 0;
        dp_old[j] = 0;
    }
    
    dp_old[0] = 1;
    
    for(int x = 0; x < n; ++x){
        cin >> a[x];
        
        // Constructing sums  : O(K)
        int sum = 0;
        for(int i = 0; i <= k; ++i){
            sum = mod_ans(dp_old[i] + sum, MOD);
            sums[i] = sum;
        }
        
        // Getting new answers : O(K)
        for(int val = 0; val <= k; val++){
            dp[val] = get_sum(max(val - a[x], 0), val);
        }
        
        // Copying dp_old = dp_new  : O(K)
        for(int i = 0; i <= k; ++i){
            dp_old[i] = dp[i];
            // cout << dp[i] << "\t";
            sums[i] = 0;
            dp[i] = 0;
        }
        // cout << "\n";
    }
    
    
    cout << dp_old[k] << "\n";
    return 0;
}