#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
#define RRep(i, k, n) for (int i = k; i > (int)(n); i--)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define ALL(a)  (a).begin(),(a).end()
#define rALL(a)  (a).rbegin(),(a).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> void PrintVector(const vector<T> &vec) {for (auto val : vec) cout << val << " "; cout << endl;}
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

template<class T> int former(const vector<T> &v, T x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
}
template<class T> int latter(const vector<T> &v, T x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main()
{
    int a, b, q; cin >> a >> b >> q;
    vector<ll> s(a), t(b);
    rep(i, a) cin >> s[i];
    rep(i, b) cin >> t[i];
    s.push_back(INF);s.push_back(-INF); sort(ALL(s));
    t.push_back(INF);t.push_back(-INF); sort(ALL(t));

    rep(_, q)
    {
        ll x; cin >> x;
        ll ans = INF;

        rep(i, 2)
        {
            ll first = (i ? s[former(s, x)] : s[latter(s, x)]);
            rep(j, 2)
            {
                ll second = (j ? t[former(t, first)] : t[latter(t, first)]);
                chmin(ans, abs(x - first) + abs(first - second));
            }
        }

        rep(i, 2)
        {
            ll first = (i ? t[former(t, x)] : t[latter(t, x)]);
            rep(j, 2)
            {
                ll second = (j ? s[former(s, first)] : s[latter(s, first)]);
                chmin(ans, abs(x - first) + abs(first - second));
            }
        }
        cout << ans << endl;
    }
}