
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int N;
    cin >> N;

    int a[N], b[N];
    REP(i, N) cin >> a[i] >> b[i];

    set<int> p[N], q[N];

    REP(i, N) {
        int c, d;
        cin >> c >> d;

        REP(j, N) {
            if (a[j] < c && b[j] < d) {
                p[j].insert(i);
                q[i].insert(j);
            }
        }
    }

    set<int> op, oq;
    REP(i, N) {
        op.insert(i);
        oq.insert(i);
    }

    int ans = 0;
    REP(i, N) {
        int m = inf;
        int k = -1;
        for (auto e: op) {
            if (p[e].size() < m) {
                m = p[e].size();
                k = e;
            }
        }
        op.erase(k);

        if (p[k].size() < 1) continue;

        ++ans;

        m = inf;
        int l = -1;
        for (auto e: p[k]) {
            if (q[e].size() < m) {
                m = q[e].size();
                l = e;
            }
        }
        oq.erase(l);

        for (auto e: op) {
            p[e].erase(l);
        }

        for (auto e: oq) {
            q[e].erase(k);
        }
    }

    cout << ans << endl;
}
