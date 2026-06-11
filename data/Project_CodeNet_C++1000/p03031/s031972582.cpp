#include <bits/stdc++.h>
using namespace std;
// rep macro
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rev(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rev2(i, s, n) for (int i = (int)(n) - 1; i >= (int)(s); i--)
#define bitrep(i, n) for (int i = 0; i < (int)(1 << n); i++)
// vector macro
#define all(v) v.begin(), v.end()
// math macro
#define lcm(a, b) a / __gcd(a, b) * b
// print macro
#define println(x) cout << x << endl
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")
// pair macro
#define x first
#define y second
using pii = pair<int, int>;
using pdd = pair<double, double>;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> k(m);
    vector<vector<int>> s(m, vector<int>());
    rep(i, m)
    {
        cin >> k[i];
        rep(j, k[i])
        {
            int sij; cin >> sij;
            s[i].push_back(sij - 1);
        }
    }
    vector<int> p(m);
    rep(i, m) cin >> p[i];
    int cnt = 0;
    bitrep(b, n)
    {
        bitset<10> bs(b);
        bool all_on = true;
        rep(i, m)
        {
            int switch_on = 0;
            rep(j, k[i])
            {
                if (bs[s[i][j]] == 1) { switch_on++; }
            }
            if (switch_on % 2 != p[i]) { all_on = false; break; }
        }
        if (all_on) cnt++;
    }
    cout << cnt << endl;
}