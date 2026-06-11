#include <bits/stdc++.h>
using namespace std;  

int main() {
    int x, tem, ans;
    cin >> x;
    
    ans = 1;
    for ( int i = 2; i <= x ; i++ ) {
        tem = i * i;
        while ( tem <= x ) {
            ans = max(ans, tem);
            tem *= i;
        }
    } 
    
    cout << ans << endl;
    
    return (0);
}