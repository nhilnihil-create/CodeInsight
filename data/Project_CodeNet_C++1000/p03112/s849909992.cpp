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
    int a, b, q;
    cin >> a >> b >> q;
    vector<i64> s(a+2), t(b+2), x(q);
    for(int i = 0; i < a; ++i)
        cin >> s[i+1];
    for(int i = 0; i < b; ++i)
        cin >> t[i+1];
    for(int i = 0; i < q; ++i)
        cin >> x[i];
    s[0] = t[0] = -1e15;
    s[a+1] = t[b+1] = 1e15;

    for(int i = 0; i < q; ++i){
        i64 ans = INF;
        auto ls = lower_bound(s.begin(), s.end(), x[i]);
        auto lt = lower_bound(t.begin(), t.end(), x[i]);
        i64 xb = *prev(ls);
        i64 yb = *prev(lt);
        i64 xf = *ls;
        i64 yf = *lt;
        i64 dxb = x[i] - xb;
        i64 dyb = x[i] - yb;
        i64 dxf = xf - x[i];
        i64 dyf = yf - x[i];

        chmin(ans, max(dxb, dyb));
        chmin(ans, max(dxf, dyf));
        chmin(ans, dxb + dyf + min(dxb, dyf));
        chmin(ans, dxf + dyb + min(dxf, dyb));
        cout << ans << endl;
    }
}
