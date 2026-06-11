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
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<vector<i64>> v(40, vector<i64>(2, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 40; ++j)
            ++v[j][1 ^ ((a[i] >> j) & 1)];
    }
    vector<i64> r(40, 0);
    for(int i = 0; i < 40; ++i)
        r[i] = max(v[i][0], v[i][1]) * (1LL << i);
    for(int j = 0; j < 39; ++j)
        r[j + 1] += r[j];
    i64 ans = 0;
    i64 sum = 0;
    for(int i = 39; i >= 0; --i){
        if(k & (1LL << i)){
            chmax(ans, sum + (v[i][0] * (1LL << i)) + (i ? r[i - 1] : 0));
        }
        sum += v[i][(k >> i) & 1] * (1LL << i);
    }
    cout << max(ans, sum) << endl;
}
