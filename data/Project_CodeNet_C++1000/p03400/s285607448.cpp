#ifndef DEBUG
#pragma GCC optimize("O3,unroll-loops")
#pragma loop_opt(on)
#endif
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define FAST ;
#else
#define FAST ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define cerr
#endif
#define _ <<' '<<
#define Fr(i, s, e) for(auto i = s; i < e; ++i)
#define All(v) v.begin(),v.end()
#define Ft first
#define Sd second
using ll = long long;
using pii = pair<int, int>;
constexpr ll MOD = 1e9+7;

signed main() {
    FAST;

    int n, d, x;
    cin >> n >> d >> x;
    Fr(i, 0, n) {
        int a;
        cin >> a;
        x += (d-1)/a+1;
    }
    cout << x << endl;

}
