#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define Repr(i, n, a) for (int i = (n); i >= (a); i--)
#define rep(i, n) Rep(i, 0, n)
#define repr(i, n) Repr(i, n, 0)
#define all(a) a.begin(), a.end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    rep(i, n) if (s[i] == 'R') cnt++;
    cout << (2 * cnt > n ? "Yes" : "No") << endl;
}