#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<ll> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<ll> b(n);
    
    b[0] = a[0];
    
    for (int i = 1; i < n; i++) {
        b[i] = b[i - 1] + a[i];
    }
    
    ll ans = 1LL << 60;
    
    for (int i = 1; i < n - 2; i++) {
        ll p0 = b[0], q0 = b[i] - b[0], p1 = b[i - 1], q1 = b[i] - b[i - 1];
        ll r0 = b[i + 1] - b[i], s0 = b[n - 1] - b[i + 1], r1 = b[n - 2] - b[i], s1 = b[n - 1] - b[n - 2];
    
        
        {
            int ok = -1;
            int ng = i;
            
            while(ng - ok > 1) {
                int m = (ng + ok) / 2;
                
                ll p = b[m], q = b[i] - b[m];
                
                if (p < q) {
                    ok = m;
                } else {
                    ng = m;
                }
            }
            
            if (ok != -1) {
                p0 = b[ok];
                q0 = b[i] - b[ok];
            }
            
            if (ng != i) {
                p1 = b[ng];
                q1 = b[i] - b[ng];
            }
            
        }
        
        
        {
            int ok = i;
            int ng = n - 1;
            
            while(ng - ok > 1) {
                int m = (ng + ok) / 2;
                
                ll r = b[m] - b[i], s = b[n - 1] - b[m];
                
                if (r < s) {
                    ok = m;
                } else {
                    ng = m;
                }
            }
            
            
            if (ok != i) {
                r0 = b[ok] - b[i];
                s0 = b[n - 1] - b[ok];
            }
            
            if (ng != n - 1) {
                r1 = b[ng] - b[i];
                s1 = b[n - 1] - b[ng];
            }
            
        }
        
        ans = min({ans, 
                   max({p0, q0, r0, s0}) - min({p0, q0, r0, s0}),
                   max({p1, q1, r0, s0}) - min({p1, q1, r0, s0}),
                   max({p0, q0, r1, s1}) - min({p0, q0, r1, s1}),
                   max({p1, q1, r1, s1}) - min({p1, q1, r1, s1})});
    }
    
    cout << ans << endl;
}
