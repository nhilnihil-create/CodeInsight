#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll X;
    cin >> X;
    
    ll ans = 0;
    for ( ll i = 1; i < 40; ++i){
        ll y = i;
        for ( ll j = 2; j <= 10; ++j){
            y *= i;
            if ( y > X ) break;
            chmax(ans,y);
        }
    }
    cout << ans << endl;
    
    return 0;
}
