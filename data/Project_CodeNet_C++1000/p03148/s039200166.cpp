#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll N, K;
    cin >> N >> K;

    vector<ll> t(N), d(N);
    rep(i, N) cin >> t[i] >> d[i];

    typedef pair<ll, ll> P;
    vector<P> f(t.size());
    rep(i, t.size()) f[i] = P(d[i], t[i]);
    
    sort(all(f));
    reverse(all(f));

    vector<int> cnt(N + 1);
    rep(i, K) {
        // ネタをカウント
        cnt[f[i].second]++;
    }

    ll nNeta = 0;
    rep(i, cnt.size()) {
        if (cnt[i] >= 1) nNeta++;
    }

    ll base = nNeta * nNeta;
    rep(i, K) {
        base += f[i].first;
    }

    // ~Kで入れ替え可能
    vector<P> to;
    for (int i = K - 1; i >= 0; i--) {
        if (cnt[f[i].second] >= 2) {
            to.push_back(f[i]);
        }
    }

    vector<ll> Sto(to.size());
    if (to.size() >= 1) {
        Sto[0] = to[0].first;
    }
    repi(i, to.size()) {
        Sto[i] = Sto[i - 1] + to[i].first;
    }

    // K~で入れ替え可能
    vector<P> from;
    for (int i = K; i < N; i++) {
        if (cnt[f[i].second] <= 0) {
            from.push_back(f[i]);
        }
        cnt[f[i].second]++;
    }

    vector<ll> Sfrom(from.size());
    if (from.size() >= 1) {
        Sfrom[0] = from[0].first;
    }
    repi(i, from.size()) {
        Sfrom[i] = Sfrom[i - 1] + from[i].first;
    }


    ll res = base;
    for (int nSwap = 1; nSwap <= K; nSwap++) {
        if (Sto.size() <= nSwap - 1 || Sfrom.size() <= nSwap - 1) {
            continue;
        }
        // 1~Kと重複のないものをK+1~からnSwap個選んで、
        // それを1~Kの重複のあるものをコストが小さい順に並び替えることを考える
        ll v = base - Sto[nSwap-1] + Sfrom[nSwap-1];
        v = v - nNeta*nNeta + (nSwap + nNeta) * (nSwap + nNeta);
        res = max(res, v);        
    }

    put(res);
}
signed main(){ Main();return 0;}