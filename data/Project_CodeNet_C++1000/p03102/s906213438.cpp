#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int a, n, m, c, cnt = 0, ans = 0;
    cin >> n >> m >> c;
    vector<int>b(m);
    rep(i, m)cin >> b[i];
    rep(i, n) {
        cnt = c;
        rep(j, m) {
            cin >> a;
            cnt += a * b[j];
        }
        if (cnt > 0)ans++;
    }
    cout << ans << endl;
    return 0;
}