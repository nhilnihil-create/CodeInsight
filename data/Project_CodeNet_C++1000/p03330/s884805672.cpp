#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll d[50][50];
ll s[550][550];

int main(){
    int n, c;
    cin >> n >> c;
    rep(i, c) rep(j, c) cin >> d[i][j];
    rep(i, n) rep(j, n) cin >> s[i][j];

    vector<ll> p, q, r;

    rep(i, n) rep(j, n){
        if ((i+j)%3 == 0) p.push_back(s[i][j]);
        if ((i+j)%3 == 1) q.push_back(s[i][j]);
        if ((i+j)%3 == 2) r.push_back(s[i][j]);
    }

    vector<P> pp, qq, rr;
    for(int to = 1; to <= c; to++){
        ll tmpp = 0;
        ll tmpq = 0;
        ll tmpr = 0;
        rep(j, p.size()) tmpp += d[p[j]-1][to-1];
        rep(j, q.size()) tmpq += d[q[j]-1][to-1];
        rep(j, r.size()) tmpr += d[r[j]-1][to-1];
        pp.push_back(make_pair(tmpp, to));
        qq.push_back(make_pair(tmpq, to));
        rr.push_back(make_pair(tmpr, to));
    }
    sort(pp.begin(), pp.end());
    sort(qq.begin(), qq.end());
    sort(rr.begin(), rr.end());

    ll ans = LINF;
    rep(i, 3){
        rep(j, 3){
            rep(k, 3){
                if (pp[i].second == qq[j].second || pp[i].second == rr[k].second || rr[k].second == qq[j].second) continue;
                ans = min(ans, pp[i].first+qq[j].first+rr[k].first);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
