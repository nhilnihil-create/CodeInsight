#include <bits/stdc++.h>
using namespace std;  

int main(){
    int n, c[20], v[20], x, y, ans;
    
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> c[i];
    }
    for ( int i = 0; i < n; i++ ) {
        cin >> v[i];
    }
     
    ans = 0;
    for ( int i = 0; i < (1<<n); i++ ) {
        x = y = 0;
        for ( int j = 0; j < n; j++ ) {
            if ( i & (1<<j) ) {
                x += c[j];
                y += v[j];
            }
        }
        ans = max(ans, x-y);
    }
     
    cout << ans << endl;
     
    return (0);
}
