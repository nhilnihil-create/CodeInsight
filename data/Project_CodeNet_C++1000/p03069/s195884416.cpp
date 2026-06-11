#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = b-1; i >= a; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
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

////////////////////////////////////////////////////////
// 左(自分を含む)にある#の個数、右にある.の個数
ll cntl[300000], cntr[300000];

int main() {
    ll n; cin >> n;
    string s; cin >> s;

    rep(i, 0, n){
        if(s[i] == '#') cntl[i]++;
        cntl[i+1] += cntl[i];
    }
    repr(i, 1, n){
        if(s[i] == '.') cntr[i-1]++;
        if(i != 1) cntr[i-2] += cntr[i-1];
    }
    ll ans = 300000;
    rep(i, 0, n){
        chmin(ans, cntl[i]+cntr[i]);
    }
    if(s[0] == '.') cntr[0]++;
    chmin(ans, cntr[0]);
    co(ans);

    return 0;
}


