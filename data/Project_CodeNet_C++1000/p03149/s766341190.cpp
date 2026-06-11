#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define fi first
#define se second
#define pb push_back
#define int long long

int a[5], b[5];
signed main()  {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false);   cout.tie(0);
    FOR(i, 1, 4)    {
        int x; cin >> x;
        if(x == 1) b[1] = 1;
        if(x == 9) b[2] = 1;
        if(x == 7) b[3] = 1;
        if(x == 4) b[4] = 1;
    }
    FOR(i, 1, 4) if(!b[i])
        return cout << "NO", 0;
    return cout << "YES", 0;
}
