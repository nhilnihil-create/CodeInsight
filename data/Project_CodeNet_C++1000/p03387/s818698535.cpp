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

    array<int,3> v;
    for(auto &x: v) cin >> x;
    sort(All(v));
    int c = 0;
    Fr(i, 0, 2) {
        int x = (v[2]-v[i])/2;
        v[i] += x*2;
        c += x;
    }
    sort(All(v));
    if (v[0] == v[2]-1) {
        if (v[0]==v[1]) c++;
        else c+=2;
    }
    cout << c << endl;

}
