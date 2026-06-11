#include <bits/stdc++.h>
#define rep(i, a) for(int i = 0; i < a; i++)
#define all(v) v.begin(), v.end()
#define int long long
using namespace std;
signed main() {
    int a, b, k;
    cin >> a >> b >> k;
    rep(i, k / 2) {
        if(a % 2 != 0) a -= 1;
        a /= 2;
        b += a;
        if(b % 2 != 0) b -= 1;
        b /= 2;
        a += b;
    }
    if(k % 2 != 0) {
        if(a % 2 != 0) a -= 1;
        a /= 2;
        b += a;
    }
    cout << a << " " << b<<endl;
    return 0;
}