#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N,K;
    cin >> N >> K;
    
    ll ans = 1;
    REP(i,N){
        ll ans1 = ans * 2, ans2 = ans + K;
        if ( ans1 > ans2 ) ans = ans2;
        else ans = ans1;
    }
    
    cout << ans << endl;
    
    return 0;
}
