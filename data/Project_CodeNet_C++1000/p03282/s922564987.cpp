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
    string s;
    int k;
    cin >> s >> k;
    int cta = 0;
    rep(i, min((int)s.length(), k)) if (s[i] == '1') cta++;
    if (cta == k)
        cout << 1 << endl;
    else
    {
        rep(i, k)
        {
            if (s[i] != '1')
            {
                cout << s[i] << endl;
                return;
            }
        }
    }
}
int main(void)
{
    solve();
}