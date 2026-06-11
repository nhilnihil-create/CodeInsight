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
    vector<string> S(N);
    vector<ll> num(5,0);
    REP(i,N){
        cin >> S[i];
        //cout << S[i][0] << endl;
        
        if ( S[i][0] == 'M' ) num[0] = num[0] + 1;
        else if ( S[i][0] == 'A' ) num[1] = num[1] + 1;
        else if ( S[i][0] == 'R' ) num[2] = num[2] + 1;
        else if ( S[i][0] == 'C' ) num[3] = num[3] + 1;
        else if ( S[i][0] == 'H' ) num[4] = num[4] + 1;
    }
    
    ll ans = 0;
    for ( int i = 0; i < 3; ++i){
        for ( int j = i + 1; j < 4; ++j){
            for ( int k = j + 1; k < 5; ++k){
                ans = ans + (num[i] * num[j] * num[k]);
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
