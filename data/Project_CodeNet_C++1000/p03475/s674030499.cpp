#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define chmax(x,y) x = max(x, y)
#define chmin(x,y) x = min(x, y)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main()
{
    int n;
    cin >> n;
    vector<int> c(n), s(n), f(n);
    rep(i, n-1) cin >> c[i] >> s[i] >> f[i];
    rep(i, n) {
        int t = 0;
        repl(j, i, n-1) {
            if(t < s[j]) t = s[j];
            else if(t % f[j] == 0);
            else t = t + f[j] - t % f[j];
            t += c[j];
        }
        cout << t << endl;
    }
    return 0;
}
