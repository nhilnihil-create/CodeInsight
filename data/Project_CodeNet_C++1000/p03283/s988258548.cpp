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
    ll n, m, q; cin >> n >> m >> q;
    vvll p(n+1, vll(n+1, 0));
    rep(i, 0, m){
        ll a, b; cin >> a >> b;
        p[a][b]++;
    }
    vvll bcum(n+2, vll(n+1, 0));
    rrep(i, n, -1){
        rep(j, 1, n+1){
            bcum[i][j] = bcum[i][j-1] + bcum[i+1][j] - bcum[i+1][j-1] + p[i][j];
        }
    }
    
    rep(i, 0, q){
        ll l, r; cin >> l >> r;
        prtl(bcum[l][r]);
    }
}
