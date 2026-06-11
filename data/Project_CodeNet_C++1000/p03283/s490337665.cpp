#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<int>>a(n,vector<int>(n));
    rep(i,m) {
        int l,r;
        cin >> l >> r;
        l--;r--;
        a[l][r]++;
    }
    vector<vector<int>>as(n+1,vector<int>(n+1));
    rep(i,n) {
        rep(j,n) {
            as[i+1][j+1] = as[i][j+1] + as[i+1][j] - as[i][j] + a[i][j];
        }
    }
    rep(i,q) {
        int l,r;
        cin >> l >> r;
        l--;
        int ans = as[r][r] - as[l][r] - as[r][l] + as[l][l];
        cout << ans << endl;
    }
}