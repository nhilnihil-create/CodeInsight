#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

constexpr i64 MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;++i){
        int c;
        cin >> c;
        v.push_back(c);
    }
    vector<pair<int, int>> rl({{v[0], 1}});
    for(int i=1;i<n;++i){
        if(v[i] == rl.back().first)rl.back().second++;
        else rl.emplace_back(v[i], 1);
    }

    vector<i64> dp(rl.size()+1);
    map<int, int> prev;
    dp[0] = 1;
    for(int i=1;i<=(int)rl.size();++i){
        dp[i] += dp[i-1];
        dp[i] %= MOD;
        if(prev.count(rl[i-1].first)){
            dp[i] += dp[prev[rl[i-1].first]];
            dp[i] %= MOD;
        }
        prev[rl[i-1].first] = i;
        //cerr << dp[i] << endl;
    }

    cout << dp[rl.size()] << endl;

    return 0;
}