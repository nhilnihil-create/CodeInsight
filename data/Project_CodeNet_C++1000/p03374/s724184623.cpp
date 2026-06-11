
#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

const ll INF = (ll)1e18;

int main(){
    int N;
    ll C;
    cin >> N >> C;
    vector<ll> x(N+1), v(N+1), vc(N+1);
    x[0] = 0;
    v[0] = 0;
    REP(i, 1, N+1) cin >> x[i] >> v[i];

    vc[0] = v[0];
    REP(i,1, N+1) {
        vc[i] = vc[i-1] + v[i];
    }

    vector<ll> r(N+1);
    r[0] = 0;
    REP(i, 1, N+1) {
        r[i] = max(r[i-1], vc[i] - x[i]);
    }

    vector<ll> l(N+1);
    l[N] = vc[N] - vc[N-1] - (C - x[N]);

    for(int i = N-1; i >= 1; i--) {
        l[i] = max(l[i+1], vc[N] - vc[i-1] - (C - x[i]));
    }

    ll ans = 0;
    rep(i, N+1) {
        ll tmp = vc[i] - x[i];
        if (tmp > ans) ans = tmp;

        if (i < N) {
            tmp = vc[i] - 2*x[i] + l[i+1];
            if ( tmp > ans ) ans = tmp;
        }
    }

    for (int i = N; i >= 1; i--) {
        ll tmp = vc[N] - vc[i-1] - (C - x[i]);
        if (tmp > ans) ans = tmp;

        tmp = vc[N] - vc[i-1] - 2 * (C - x[i]) + r[i-1];
        if (tmp > ans) ans = tmp;
    }

    cout << ans << endl;
}