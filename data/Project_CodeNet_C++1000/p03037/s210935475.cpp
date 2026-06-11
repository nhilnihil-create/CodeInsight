#include <bits/stdc++.h>
using namespace std;  

int main() {
    int n, m, l, r, sum, ans, imos[100001] = {};
    cin >> n >> m;
    
    for ( int i = 0; i < m; i++ ) {
        cin >> l >> r;
        imos[l-1] ++;
        imos[r] --;
    }
    
    ans = 0;
    sum = 0;
    for ( int i = 0; i <= n; i++ ) {
        sum += imos[i];
        
        if ( sum == m ) {
            ans ++;
        } 
    }
    
    cout << ans << endl;
    
    return (0);
}