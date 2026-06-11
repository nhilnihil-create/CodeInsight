#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
constexpr int MOD = 1e9 + 7;
signed main(){
    int N; cin >> N;
    vector<int>v(N);
    for( auto& e : v) cin >> e;
    vector<int>dp(N,0LL);
    int maxi = *max_element(v.begin(), v.end());
    vector<vector<int>>cnt(maxi+1);
    for(int i = 0; i < v.size(); ++i){
        int num = v[i];
        if(i)dp[i] += dp[i-1];
        if(cnt[num].empty() ){
            
            cnt[num].push_back(i);
            
        } else if(cnt[num].back() + 1 == i){
            cnt[num].back() = i;
        
        } else {
            int lst = cnt[num].back();
            dp[i] += dp[lst] + 1;
            dp[i] %= MOD;
            cnt[num].push_back(i);
        }
    }
    cout << dp.back() + 1 << endl;
}
