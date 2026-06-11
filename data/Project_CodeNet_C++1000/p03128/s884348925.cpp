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
int c[] = {0,2,5,5,4,5,6,3,7,6};
signed main() {  
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    // dp[i] = dp[i-c[j]]+1
    vector<int> digs(n+1, -mod);
    digs[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            if(i-c[a[j]] >= 0) {
                digs[i] = max(digs[i], digs[i-c[a[j]]]+1);
            }
        }
    }
    while(n > 0) {
        // cout << n << ": " << digs[n]-1 << endl;
        for(int j = m-1; j >= 0; j--) {
            if(n-c[a[j]] >= 0 && digs[n-c[a[j]]] == digs[n]-1) {
                // cout << "  " << a[j] << " " << digs[n-c[a[j]]] << endl;
                cout << a[j];
                n -= c[a[j]];
                break;
            } 
        }
    }
    cout << "\n";








    return 0;
    
}