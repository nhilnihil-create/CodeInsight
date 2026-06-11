#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

double dp[2][210];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> t(n), v(n);
    rep(i,n) cin >> t[i];
    rep(i,n) cin >> v[i];
    rep(i,207){
        dp[0][i] = -1;
        dp[1][i] = -1;
    }
    dp[0][0] = 0;
    rep(i,n){
        rep(j,t[i]*2){
            rep(k,v[i]*2+1){
                if(k < v[i]*2 && dp[0][k+1] != -1){
                    chmax(dp[1][k], dp[0][k+1] + (k+0.5)*0.25);
                }
                if(dp[0][k] != -1){
                    chmax(dp[1][k], dp[0][k] + k*0.25);
                }
                if(k > 0 && dp[0][k-1] != -1){
                    chmax(dp[1][k], dp[0][k-1] + (k-0.5)*0.25);
                }
            }
            rep(k,207){
                dp[0][k] = dp[1][k];
                dp[1][k] = -1;
            }
        }
    }
    cout << fixed << setprecision(12) << dp[0][0] << endl;
    return 0;
}