#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N, C;
int D[31][31];
int c[501][501];
int Z[31], O[31], T[31];

int draw(int zer, int one, int two){
    int ret = 0;
    rep(i,C){
        ret += D[i][zer]*Z[i] + D[i][one]*O[i] + D[i][two]*T[i];
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> C;
    rep(i,C)rep(j,C) cin >> D[i][j];
    rep(i,C){
        Z[i] = 0;
        O[i] = 0;
        T[i] = 0;
    }
    rep(i,N)rep(j,N){
        cin >> c[i][j];
        c[i][j]--;
        if((i+j)%3 == 0) Z[c[i][j]]++;
        else if((i+j)%3 == 1) O[c[i][j]]++;
        else T[c[i][j]]++;
    }
    int ans = 1e9;
    rep(i,C){
        rep(j,C){
            if(i == j) continue;
            rep(k,C){
                if(i == k || j == k) continue;
                chmin(ans, draw(i,j,k));
            }
        }
    }
    cout << ans << endl;
    return 0;
}