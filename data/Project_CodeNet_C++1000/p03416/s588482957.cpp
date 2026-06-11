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
bool f(int x)
{
    vector<int> v;
    while (x > 0)
        v.push_back(x % 10), x /= 10;
    reverse(all(v));
    rep(i, v.size() / 2)
    {
        if (v[i] != v[v.size() - 1 - i])
            return false;
    }
    return true;
}
void solve(void)
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; ++i)
    {
        if (f(i))
            ans++;
    }
    cout << ans << endl;
}
int main(void)
{
    solve();
}