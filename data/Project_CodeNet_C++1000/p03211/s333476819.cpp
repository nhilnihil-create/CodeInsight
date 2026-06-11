#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
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
    string s;
    cin >> s;
    int ans = (int)INF;
    rep(i, 0, s.length() - 2) ans = min(ans, abs(753 - stoi(s.substr(i, 3))));
    cout << ans << endl;
}
