#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,m,c;
    cin >> n >> m >> c;
    vector<int> b(m);
    vector<vector<int>> a(n, vector<int>(m));
    rep (i, m) cin >> b[i];
    rep (i, n) {
        rep (j, m) cin >> a[i][j];
    }
    int cnt=0;
    rep (i, n) {
        int sum=c;
        rep (j, m) {
            sum += b[j] * a[i][j];
        }
        if (sum > 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}