#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){
    int H, W; cin >> H >> W;
    vector<vector<int>> c(10, vector<int>(10,0));
    rep(i,10) rep(j,10) cin >> c[i][j];

    vector<vector<int>> A(H, vector<int>(W,0));
    rep(i,H) rep(j,W) cin >> A[i][j];

    rep(k,10){
        rep(i,10){
            rep(j,10){
                c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
            }
        }
    }
    ll ans = 0;
    rep(i,H){
        rep(j,W){
            if (A[i][j] == -1) continue;
            ans += c[A[i][j]][1];
        }
    }

    cout << ans << endl;
}