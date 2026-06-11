#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, k;
    string s;
    
    cin >> n >> k;
    cin >> s;
    
    for ( int i = 0; i < n; i++ ) {
        if ( i != k-1) {
            cout << s[i];
        } else {
            cout << char(s[i] - 'A' + 'a');
        }
    }
    cout << endl;
    return (0);
}