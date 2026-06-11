#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 40;
typedef pair<ll, ll> P;
int main()
{
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> td(N);
    rep(i, N) {
        ll t, d;
        cin >> t >> d;
        t--;
        td[t].push_back(d);
    }
    rep(i, N) {
        if ((int)td[i].size() == 0) td[i].push_back(-INF);
        sort(all(td[i]));
        reverse(all(td[i]));
    }
    sort(all(td), [](vector<ll> a, vector<ll> b) {
                        return (a[0] > b[0]);   
                    });
    ll res = 0;
    priority_queue<ll, vector<ll>> que;

    rep(i, K) {
        res += td[i][0];
        repd(j, 1, td[i].size()) que.push(td[i][j]);
    }

    repd(i, K, N) {
        rep(j, td[i].size()) que.push(td[i][j]);
    }

    ll ans = res + K * K;
    for (ll k = K - 1; k > 0; k--) {
        ll ct = que.top();
        if (ct > td[k][0]) {
            res -= td[k][0];
            res += ct;
            que.pop();
            que.push(td[k][0]);
        }
        chmax(ans, res + k * k);
    }

    cout << ans << endl;
    return 0;
}