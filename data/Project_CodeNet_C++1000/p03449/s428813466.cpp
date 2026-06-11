#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
    int n;
    cin>>n;
    int a[2][n];
    rep(i, 2) rep(j, n) cin >> a[i][j];

    int ans = 0;
    rep(i, n) {
        int candies = 0;
        rep(j, i + 1) candies += a[0][j];
        rep2(j, i, n) candies += a[1][j];
        ans = max(ans, candies);
    }
    cout << ans << endl;
    return 0;
}