#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> f(n, vector<int>(10)), p(n, vector<int>(11));
    rep(i,n)rep(j,10) cin >> f[i][j];
    rep(i,n)rep(j,11) cin >> p[i][j];
    int ans = -INF;
    for(int S = 1; S < (1<<10); S++){
        int score = 0;
        rep(i,n){
            int c = 0;
            rep(j,10){
                if(f[i][j] && (S>>j & 1)) c++;
            }
            score += p[i][c];
        }
        chmax(ans, score);
    }
    cout << ans << endl;
    return 0;
}