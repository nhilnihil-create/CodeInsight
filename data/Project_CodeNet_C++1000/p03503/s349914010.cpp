#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////

// 2^10　全パターンを試す

int main() {
    ll n; cin >> n;
    vector<Vl> f(n, Vl(10));
    rep(i, 0, n){
        rep(j, 0, 10) cin >> f[i][j];
    }
    vector<Vl> p(n, Vl(11));
    rep(i, 0, n){
        rep(j, 0, 11) cin >> p[i][j];
    }

    ll ans = -INF;

    for(int tmp = 1; tmp < (1 << 10); tmp++){
        bitset<10> s(tmp);

        Vl cnt(n, 0);
        rep(i, 0, n){
            rep(j, 0, 10){
                if(s.test(j) && f[i][j]) cnt[i]++;
            }
        }

        ll sum = 0;
        rep(i, 0, n){
            sum += p[i][cnt[i]];
        }

        chmax(ans, sum);

    }
    co(ans);

    return 0;
}
