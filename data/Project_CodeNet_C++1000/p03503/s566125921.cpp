#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    cin >> n;
    vector<vector<int>>f(n,vector<int>(10));
    rep(i,n) rep(j,10) cin >> f[i][j];
    vector<vector<int>>p(n,vector<int>(11));
    rep(i,n) rep(j,11) cin >> p[i][j];
    ll ans = -1000000000;
    for(int bit = 1;bit < (1<<10);bit++) {
        ll tmp = 0;
        rep(i,n) {
            int cnt = 0;
            rep(j,10) {
                if(bit & 1<<j && f[i][9-j] == 1) cnt++; 
            }
            tmp += p[i][cnt];
        }
        ans = max(ans,tmp);
    }
    cout << ans << endl;
}