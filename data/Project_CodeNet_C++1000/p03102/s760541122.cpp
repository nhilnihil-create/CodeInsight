#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    int ans = 0;
    rep(i,n) {
        int cnt = 0;
        rep(j,m) {
            int a;
            cin >> a;
            cnt += a*b[j];
        }
        cnt += c;
        if (cnt > 0) ans++;
    }
    cout << ans << endl;
    return 0;
}