#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e+10;

int main() {
    string S;
    cin >> S;
    
    int t = S.size();
    
    int ans = INF;
    
    REP(i,t-1){
        if ( S[i] != S[i+1] ) {
            int c;
            int pos = i + 1;
            c = max(pos,t-pos);
            ans = min(ans,c);
        }
    }
    
    if ( ans == INF ) ans = t;
    
    cout << ans << endl;
    
    
    return 0;
}
