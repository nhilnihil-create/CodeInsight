#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    rep(i, 0, m) cin >> b[i];
    vector<vector<int>> a(n, vector<int> (n));
    rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];
    int ans = 0;
    rep(i, 0, n){
        int sum = 0;
        rep(j, 0, m) sum += a[i][j]*b[j];
        if(sum > -c) ans++;
    }
    cout << ans << endl;
    return 0;
}
