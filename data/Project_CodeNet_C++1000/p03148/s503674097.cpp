#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
using Graph = vector<vector<int>>;
using Graphl = vector<vector<ll>>;
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
const long long minusINF = -(1LL << 40);
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    ll n, k; cin >> n >> k;
    Graphl s(n);
    rep(i, n)
    {
        ll t, d; cin >> t >> d; --t;
        s[t].push_back(d);
    }

    for(auto &v : s)
    {
        sort(rALL(v));
        if (v.empty()) v.push_back(minusINF);
    }

    sort(ALL(s), [&](vector<ll> a, vector<ll> b) {return a[0] > b[0];});

    ll cur = 0;
    priority_queue<ll> q;
    rep(i, k)
    {
        cur += s[i][0];
        Rep(j, 1, s[i].size()) q.push(s[i][j]);
    }
    Rep(i, k, n) rep(j, s[i].size()) q.push(s[i][j]);

    ll ans = cur + k * k;
    for (ll x = k - 1; x >= 1; --x)
    {
        ll v = s[x][0];
        ll w = q.top();
        if (v < w)
        {
            q.pop(); cur += w;
            q.push(v); cur -= v;
        }
        ans = max(ans, cur + x * x);
    }
    cout << ans << endl;
}