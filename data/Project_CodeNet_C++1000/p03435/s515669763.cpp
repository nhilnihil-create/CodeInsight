#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    vector<vector<int>> c(3,vector<int>(3));
    rep(i,3){
        rep(j,3) cin >> c[i][j];
    }
    bool ok = true;
    if (c[0][0] - c[0][1] != c[1][0] - c[1][1]) ok = false;
    if (c[0][0] - c[0][1] != c[2][0] - c[2][1]) ok = false;
    if (c[0][0] - c[0][2] != c[1][0] - c[1][2]) ok = false;
    if (c[0][0] - c[0][2] != c[2][0] - c[2][2]) ok = false;
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}