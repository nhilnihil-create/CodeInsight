#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;

template <typename T>
bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}


signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    auto comp = a;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    vector<int> bef_pos(comp.back(), -1);
    vector<int> bef_arr(n, -1);
    for(int i = 0; i < n; ++i){
        a[i] = distance(comp.begin(), lower_bound(comp.begin(), comp.end(), a[i]));
        bef_arr[i] = bef_pos[a[i]];
        bef_pos[a[i]] = i;
    }
    vector<int> dp(n, 0);
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        i64 cnt = (bef_arr[i] == -1 || bef_arr[i] == i - 1 ? 0 : dp[bef_arr[i]]);
        dp[i] = (dp[i - 1] + cnt) % MOD;
    }
    cout << dp.back() << endl;
}
