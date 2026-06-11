#include <bits/stdc++.h>
using namespace std;  

int main() {
    int ans;
    string s;
    
    cin >> s;
    ans = 0;
    
    for ( int i = 0; i < 3; i++ ) {
        if ( s[i] == 'o' ) {
            ans+=100;
        }
    }
    
    cout << 700 + ans << endl;
    
    return (0);
}