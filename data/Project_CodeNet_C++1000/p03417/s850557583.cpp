#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll N,M;
    cin >> N >> M;
    
    ll ans;
    if ( N == 1 ) {
        if ( M == 1 ){
            ans = 1;
        } else {
            ans = M - 2;
        }
    } else if ( M == 1 ){
        ans = N - 2;
    } else {
        ans = ( N-2 ) * ( M-2 );
    }
    
    cout << ans << endl;
    
    return 0;
}
