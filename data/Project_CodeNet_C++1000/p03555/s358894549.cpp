#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

char c[2][3];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    rep(i,2)rep(j,3) cin >> c[i][j];
    if(c[0][0] == c[1][2] && c[0][1] == c[1][1] && c[0][2] == c[1][0]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}