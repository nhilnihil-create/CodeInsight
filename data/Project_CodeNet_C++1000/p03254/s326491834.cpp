#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repm(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll a, b, c, m, n, ans;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> a;
    vl c(n);
    rep(i, n) cin >> c[i];
    sort(c.begin(), c.end());
    int count = 0;
    rep(i, n - 1)
    {
        if (a - c[i] < 0)
            break;
        a -= c[i];
        count++;
    }
    if (a == c[n - 1])
        count++;

    cout << count << endl;

    return 0;
}