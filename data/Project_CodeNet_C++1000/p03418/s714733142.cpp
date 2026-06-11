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
    
    ll ans = 0;
    for ( int b = K + 1; b <= N; ++b){
        int x = N / b;
        int y = N % b;
        ll num = 0;
        if ( K == 0 ){
            num = N;
        } else {
            num = x * ( b - K ) + max(0,y-K+1);
        }
        ans += num;
    }
    
    cout << ans << endl;
    
    return 0;
}
