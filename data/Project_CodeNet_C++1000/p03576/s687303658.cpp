#include <bits/stdc++.h>
#define INF 1e18 * 5
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}


void solve() {
    int N,K;
    cin >> N >> K;
    vector<pair<ll,ll>> v(N);
    vector<ll> vx(N);
    vector<ll> vy(N);
    REP(i,N) {
        ll x,y;
        cin >> x >> y;
        v[i] = make_pair(x,y);
        vx[i] = x;
        vy[i] = y;
    }

    sort(ALL(vx));
    sort(ALL(vy));

    ll ans = INF;
    // x1,x2,y1,y2を決定
    REP(x1i,N-1) {
        FOR(x2i,x1i+1,N) {
            REP(y1i,N-1) {
                FOR(y2i, y1i+1,N) {
                    auto x1 = vx[x1i];
                    auto x2 = vx[x2i];
                    auto y1 = vy[y1i];
                    auto y2 = vy[y2i];

                    auto cnt = 0;

                    REP(i,N) {
                        auto x = v[i].first;
                        auto y = v[i].second;
                        auto cond1 = x1 <= x && x <= x2;
                        auto cond2 = y1 <= y && y <= y2;
                        if(cond1 && cond2) cnt++;
                    }

                    if(cnt >= K) chmin(ans,(x2-x1)*(y2-y1));

                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
