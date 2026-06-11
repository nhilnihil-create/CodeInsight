#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define INF 10e7
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;
void solve(void)
{
    int n, d, x;
    cin >> n >> d >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<set<int>> vs(d);
    rep(i, n)
    {
        for (int j = 0; a[i] * j < d; ++j)
        {
            int tmp = a[i] * j;
            vs[tmp].insert(i);
        }
    }
    int ans = 0;
    for (auto i : vs)
        ans += i.size();
    cout << ans + x << endl;
}
int main(void)
{
    solve();
}