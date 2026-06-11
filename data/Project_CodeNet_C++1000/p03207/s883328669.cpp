#include <bits/stdc++.h>
using namespace std;  

int main(){
    int n, p, ans, m;
    cin >> n;
    ans = m = 0;
    for ( int i = 0; i < n; i++ ) {
        cin >> p;
        m = max(m, p);
        ans += p;
    }
    
    cout << ans - m/2 << endl;
    return (0);
}
