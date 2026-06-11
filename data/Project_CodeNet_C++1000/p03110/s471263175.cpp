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
    ll n;
    cin >> n;
    double ans = 0;
    rep(i, 0, n)
    {
        string tmp, x;
        cin >> tmp >> x;
        if (x == "JPY")
            ans += stod(tmp);
        else
            ans += stod(tmp) * 380000;
    }
    cout << ans << endl;
}
