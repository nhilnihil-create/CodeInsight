#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    rep(i,2) {
       rep(j,n) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    rep(i,n){
        int pick = 0;
        rep(j,i+1) {
            pick += a[0][j];
        }
        for (int j = i; j < n; ++j) {
            pick += a[1][j];
        }
        if (ans < pick) ans = pick;
    }

    cout << ans << endl;

    return 0;
}
