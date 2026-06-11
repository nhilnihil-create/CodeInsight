#include <bits/stdc++.h>
using namespace std;
#define INF_LL 10000000000000000
#define INF 200000000
#define MOD 1000000007
#define ll long long
#define all(x) x.begin(), x.end()
#define REP(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
// typedef float double;
// typedef priority_queue prique;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<P> vp;
typedef vector<ll> vl;
typedef vector<vi> matrix;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int sign[2] = {1, -1};
template <class T> bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

ll modpow(ll a, ll b, ll m) {
    if(b == 0)
        return 1;
    ll t = modpow(a, b / 2, m);
    if(b & 1) {
        return (t * t % m) * a % m;
    } else {
        return t * t % m;
    }
}
struct edge {
    int to;
    ll cost;
    edge(int t, ll c) { to = t, cost = c; }
};

int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    vl d(n + 1), m(n + 1), c(n + 1);
    rep(i, n) {
        d[i + 1] += d[i];
        m[i + 1] += m[i];
        c[i + 1] += c[i];
        if(s[i] == 'D') {
            d[i + 1]++;
        } else if(s[i] == 'M') {
            m[i + 1]++;
        } else if(s[i] == 'C') {
            c[i + 1]++;
        }
    }
    rep(_, q) {
        ll res = 0;
        int k;
        cin >> k;
        rep(i, n) {
            if(s[i] == 'D') {
                res -= (c[min(n, i + k)] - c[i]) * m[i];
            } else if(s[i] == 'C') {
                res += (d[i] - d[max(0, i - k + 1)]) * m[i];
            }
        }
        cout << res << endl;
    }
}
