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
    vector<int> c(n - 1), s(n - 1), f(n - 1);
    for(int i = 0; i < n - 1; ++i)
        cin >> c[i] >> s[i] >> f[i];
    for(int st = 0; st < n; ++st){
        vector<int> ans(n, MOD);
        ans[st] = 0;
        for(int i = st; i < n - 1; ++i){
            int tim = max(ans[i], s[i]);
            if(tim % f[i] != 0)
                tim += (f[i] - (tim % f[i]));
            chmin(ans[i + 1], tim + c[i]);
        }
        cout << ans.back() << endl;
    }
}
