#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(ll i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const int MOD = 1000000007;

ll S(ll n) {
    string s = to_string(n);
    ll res = 0;
    REP(i, s.length()) { res += s[i] - '0'; }
    return res;
}
double snuke(ll n) { return (double)((double)n / (double)S(n)); }

ll fact(ll n) {
    ll res = 1;
    REP(i, n) { res *= 10; }
    return res;
}

ll K;
vector< pair<ll, double> > cand;
vector<ll> ans;

signed main()
{
    cin >> K;

    ll nines[16] = {};
    for(ll i = 1; i < 16; ++i) {
        nines[i] = nines[i-1] + fact(i-1) * 9;
    }

    // 強そうなやつを列挙
    for(ll i = 1; i < 10; ++i) { cand.push_back({i, 1}); }
    for(ll i = 0; i < 1000; ++i) {
        for(ll j = 1; j < 16; ++j) {
            ll tmp = i * fact(j) + nines[j];
            cand.push_back(make_pair(tmp, snuke(tmp)));
        }
    }
    SORT(cand);
    cand.erase(unique(cand.begin(), cand.end()), cand.end());

    // 最強ではなかったやつを消していく
    REP(i, cand.size()) {
        bool isStrong = true;
        for(ll j = i + 1; j < cand.size(); ++j) {
            if(cand[i].second > cand[j].second) {
                isStrong = false;
                break;
            }
        }
        if(isStrong) { ans.push_back(cand[i].first); }
    }

    // 答えの表示
    REP(i, K) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
