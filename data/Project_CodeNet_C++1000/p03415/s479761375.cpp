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
    vector<string> s(3);
    rep(i, 3) cin >> s[i];
    rep(i, 3) cout << s[i][i];
    cout << endl;
}
int main(void)
{
    solve();
}