#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

char C[2][3];
 
signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    rep(i, 2) rep(j, 3) cin >> C[i][j];
    if (C[0][0]==C[1][2] && C[0][1]==C[1][1] && C[0][2]==C[1][0]) cout << "YES" << endl;
    else cout << "NO" << endl;
}