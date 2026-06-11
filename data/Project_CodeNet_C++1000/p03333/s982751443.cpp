//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

void dout() { cerr << '\n'; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << " " << H;
    dout(T...);
}

#ifdef LOCAL
    #define dbg(...) cerr << #__VA_ARGS__, dout(__VA_ARGS__)
#else
    #define dbg(...) ;
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;

const int N = 1e5 + 123;
int n;
pii seg[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n;
    set <pii> L, R;
    for (int i = 1; i <= n; i++) {
        cin >> seg[i].fi >> seg[i].se;
        L.insert({seg[i].fi, i});
        R.insert({seg[i].se, i});
    }
    pii cur = *(--L.end());
    ll res1 = abs(cur.fi);
    for (int i = 1; i < n; i++) {
        int x = cur.fi;
        if (i & 1) {
            L.erase(cur);
            R.erase({seg[cur.se].se, cur.se});
            cur = *R.begin();
            if (cur.fi >= x) {
                cur.fi = x;
                break;
            }
            res1 += x - cur.fi;
        }   else {
            R.erase(cur);
            L.erase({seg[cur.se].fi, cur.se});
            cur = *(--L.end());
            if (cur.fi <= x) {
                cur.fi = x;
                break;
            }
            res1 += cur.fi - x;
        }
    }
    res1 += abs(cur.fi);

    L.clear();
    R.clear();
    for (int i = 1; i <= n; i++) {
        L.insert({seg[i].fi, i});
        R.insert({seg[i].se, i});
    }

    cur = *R.begin();
    ll res2 = abs(cur.fi);
    for (int i = 1; i < n; i++) {
        int x = cur.fi;
        if (i % 2 == 0) {
            L.erase(cur);
            R.erase({seg[cur.se].se, cur.se});
            cur = *R.begin();
            if (cur.fi >= x) {
                cur.fi = x;
                break;
            }
            res2 += x - cur.fi;
        }   else {
            R.erase(cur);
            L.erase({seg[cur.se].fi, cur.se});
            cur = *(--L.end());
            if (cur.fi <= x) {
                cur.fi = x;
                break;
            }
            res2 += cur.fi - x;
        }
    }
    res2 += abs(cur.fi);
    cout << max(res1, res2);
}
