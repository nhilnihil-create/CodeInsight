#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i,N) cin >> A[i];
    
    int ans = 0;
    REP(i,30){
        bool divisible = true;
        REP(j,N) {
            if ( A[j] % 2 != 0 ) divisible = false;
        }
        if ( divisible ){
            REP(j,N) A[j] /= 2;
            ++ans;
        } else {
            goto OUT;
        }
    }
    OUT:
    cout << ans << endl;
    
    return 0;
}
