#include <bits/stdc++.h>
using namespace std;  

int main() {
    int n, x, m, sel, sum, ans;
    cin >> n >> x;
    
    ans = n;
    sum = 0;
    sel = INT_MAX;
    for ( int i = 0; i < n; i++ ) {
        cin >> m;
        sum += m;
        sel = min(sel, m);
    }
    
    ans += (x - sum) / sel;
    cout << ans << endl;
    
    return (0);
}