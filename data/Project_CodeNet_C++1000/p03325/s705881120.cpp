#include <bits/stdc++.h>
using namespace std;  

int main() {
    int n, a, ans;
    cin >> n;
    ans = 0;
    for ( int i = 0; i < n; i++ ) {
        cin >> a;
        
        while ( a % 2 == 0 ) {
            ans ++;
            a /= 2;
        }
    }
    
    cout << ans << endl;
    return (0);
}