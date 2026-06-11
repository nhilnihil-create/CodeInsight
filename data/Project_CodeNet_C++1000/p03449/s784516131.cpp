#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    rep(i,2)rep(j,n) cin >> a[i][j];
    int ans = 0;
    for(int k = 0; k < n; ++k){
        int tmp = 0;
        for(int i = 0; i <= k; ++i) tmp += a[0][i];
        for(int i = k; i < n; ++i) tmp += a[1][i];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}