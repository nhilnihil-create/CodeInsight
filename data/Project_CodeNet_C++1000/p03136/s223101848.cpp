#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, l, one, other;
    cin >> n;
    one = 0;
    other = 0;
    
    for ( int i = 0; i < n; i++ ) {
        cin >> l;
        
        other += l;
        one = max(l, one);
    }
    
    cout << (other - one > one ? "Yes\n" : "No\n");
    return (0);
}