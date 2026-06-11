#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (ll)b; ++i)
#define digit(a) to_string(a).size()
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;
int main(void)

{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<int>> v(n);
    vector<int> b(m);
    rep(i, 0, m) cin >> b[i];
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            int temp;
            cin >> temp;
            v[i].push_back(b[j] * temp);
        }
    }
    int res = 0, ans = 0;
    rep(i, 0, n)
    {
        res = c;
        rep(j, 0, m) res += v[i][j];
        if (res > 0)
            ans++;
    }
    cout << ans << endl;
}
