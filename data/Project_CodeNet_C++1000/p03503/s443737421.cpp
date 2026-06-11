#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int f[105][10];
ll p[105][11];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i,n)rep(j,10) cin >> f[i][j];
    rep(i,n)rep(j,11) cin >> p[i][j];
    ll ans = -1e18;
    for(int S = 1; S < (1<<10); ++S){
        ll score = 0;
        rep(i,n){
            int cnt = 0;
            rep(j,10){
                if((S>>j & 1) && (f[i][j])) ++cnt;
            }
            score += p[i][cnt];
        }
        chmax(ans, score);
    }
    cout << ans << endl;
	return 0;
}