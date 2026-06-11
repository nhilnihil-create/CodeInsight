#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n,m;
    cin >> n >> m;
    int a[35][35];
    vector<int> k(n);
    rep(i,n) {
        cin >> k[i];
        rep(j,k[i]) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int l = 1;l<=m;l++) {
        int cnt = 0;
        rep(i,n) {
            rep(j,k[i]) {
                if(l == a[i][j]) {
                    cnt++;
                }
            }
        }

        if(cnt == n) ans++;
    }
    cout << ans << endl;
}