#include <bits/stdc++.h>
using namespace std;  

int main(){
    int N, T, c, t, ans;
    cin >> N >> T;
    ans = INT_MAX;
    
    for ( int i = 0; i < N; i++ ) {
        cin >> c >> t;
        
        if ( t <= T ) {
            ans = min(ans, c);
        }
    }
    
    if ( ans == INT_MAX ) {
        cout << "TLE\n";
    } else {
        cout << ans << endl;
    }
    
    return (0);
}