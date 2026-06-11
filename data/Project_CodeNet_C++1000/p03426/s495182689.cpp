#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define debug(v) cout << #v<< ": " << v <<endl;
#define fst first
#define snd second
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;
ll M = 1000000007;

int main(){
    ll h, w, d; cin >> h >> w >> d;
    vvll a(h, vll(w));
    map<ll, P> m;
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> a[i][j];
            m[a[i][j]] = mp(i, j);
        }
    }
    vvll cs(d, vll(0));
    rep(i, 0, d){
        ll x = 0+i, s = 0;
        cs[i].emplace_back(0);
        while(x <= h*w-d){
            ll o = m[x].fst, p = m[x].snd, q = m[x+d].fst, r = m[x+d].snd;
            s += abs(q-o) + abs(r-p);
            cs[i].emplace_back(s);
            x += d;
        }
    }
    ll Q; cin >> Q;
    rep(i, 0, Q){
        ll L, R; cin >> L >> R;
        ll g = L%d;
        ll e = (L-g)/d, f = (R-g)/d;
        prtl(cs[g][f] - cs[g][e]);
    }
}
