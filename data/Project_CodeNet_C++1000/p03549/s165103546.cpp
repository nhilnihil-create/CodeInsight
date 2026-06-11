#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N,M;
    cin >> N >> M;
    
    ll ans = 1900 * M + 100 * ( N - M );
    
    ll pow = 1;
    for ( int i = 0; i < M; ++i){
        pow *= 2;
    }
    
    ans *= pow;
    
    cout << ans << endl;
    
    return 0;
}
