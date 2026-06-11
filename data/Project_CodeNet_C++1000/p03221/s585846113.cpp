#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 1000000007;
const int INF = 1001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

string make_ans(int x, int y) {
    string str;
    int m = 100000;
    int r = x;
    rep(i, 6) {
        int e = r / m;
        char c = (char) e + '0';
        str += c;
        r -= m * e;
        m /= 10;
    }
    int m2 = 100000;
    int r2 = y;
    rep(i, 6) {
        int e = r2 / m2;
        char c = (char) e + '0';
        str += c;
        r2 -= m2 * e;
        m2 /= 10;
    }
    return str;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> tp(m);
    rep(i, m) {
        int y, p;
        cin >> p >> y;
        tp[i] = {y, p, i};
    }
    sort(all(tp));
    map<int,int> mp;
    vector<string> ans(m);
    rep(i, m) {
        int f = get<1>(tp[i]);
        int s = mp[f];
        ++s;
        ++mp[f];
        int k = get<2>(tp[i]);
        ans[k] = make_ans(f, s);
    }
    rep(i, m) {
        cout << ans[i] << endl;
    }
    return 0;
}
