#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    ll X,Y;
    cin >> X >> Y;
    
    
    ll ans = 1;
    REP(i,1e+7){
        X *= 2;
        if ( X <= Y ) ++ ans;
        else break;
    }
    
    cout << ans << endl;
    return 0;
}
