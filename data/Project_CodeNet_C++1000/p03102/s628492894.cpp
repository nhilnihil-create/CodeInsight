#include <bits/stdc++.h>
using namespace std;

signed main() {
    long long sum;
    int n, m, c, a[20], b[20], ans;
    
    cin >> n >> m >> c;
    for ( int i = 0; i < m; i++ ) {
        cin >> b[i];
    }
    
    ans = 0;
    for ( int i = 0; i < n; i++ ) {
        sum = 0;
        for ( int j = 0; j < m; j++ ) {
            cin >> a[j];
            
            sum += a[j] * b[j];
        }
        
        if ( sum + c > 0 ) {
            ans ++;
        }
    }
    
    cout << ans << endl;
    return (0);
}