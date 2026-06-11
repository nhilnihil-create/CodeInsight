#include <bits/stdc++.h>
#define ll long long
using namespace std;
const long long mod = 1e9+7;
long long power(long long a, long long b, long long m = mod) {
    if(b < 0) {
        return power(power(a, -b), mod-2);
    }
    long long x = 1;
    while(b) {
        if(b & 1) {
            x = 1ll * x * a % m;
        }
        a = 1ll * a * a % m;
        b /= 2;
    }
    return x;
}
const int N = 3e5+9;
signed main() {  
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int m, k; cin >> m >> k;
    if(m < 2) {
        m++;
        if(k == 0) {
            for(int i = 0; i < 2*m; i++) {
                cout << i/2 << " ";
            }
            cout << "\n";
        } else {
            cout << "-1\n";
        }
        return 0;
    }
    if(k >= (1<<m)) {
        cout << "-1\n";
        return 0;

    }
    cout << k << " ";
    for(int i = 0; i < (1<<m); i++) {
        if(i != k) cout << i << " ";
    }
    cout << k << " ";
    for(int i = (1<<m)-1; i>= 0; i--) {
        if(i != k) cout << i << " ";
    }
    cout << "\n";








    return 0;
    
}