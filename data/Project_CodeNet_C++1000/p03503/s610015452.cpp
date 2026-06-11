#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
    int N, M = 10;
    cin >> N;
    vector<vector<int>> F(N,vector<int>(10,0));
    REP(i,N) REP(j,10) cin >> F[i][j];
    vector<vector<int>> P(N,vector<int>(11,0));
    REP(i,N) REP(j,11) cin >> P[i][j];
    
    ll ans = -1e+16;
    vector<int> S;
    for ( int bit = 1; bit < (1<<M); ++bit){
        S.clear();
        for ( int i = 0; i < M; ++i) if ( bit & (1<<i) ) S.push_back(i);
        
        ll ans_sub = 0;
        for ( int i = 0; i < N; ++i){
            int num = 0;
            for ( auto a: S){
                num = num + F[i][a];
            }
            /*for ( int j = 0; j < S.size(); ++j){
                num = num + F[i][S[j]];
            }*/
            ans_sub = ans_sub + P[i][num];
        }
        if ( ans_sub > ans ) ans = ans_sub;
    }
    cout << ans << endl;
    
    return 0;
}
