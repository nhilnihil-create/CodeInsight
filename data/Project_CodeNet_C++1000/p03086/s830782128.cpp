#include <bits/stdc++.h>
using namespace std;

signed main() {
    string s;
    int ans = 0, sum;
    cin >> s;
    
    sum = 0;
    for ( int i = 0; i < s.size(); i++ ) {
        if ( s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T' ) {
            sum ++;
        } else {
            ans = max(sum, ans);
            sum = 0;
        }
    }
    
    cout << max(sum, ans) << endl;
    return (0);
}