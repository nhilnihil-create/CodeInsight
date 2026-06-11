#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ld long double
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
// const ll INF = 1LL << 30;
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


int main() {
    ll n; cin >> n;
    string ans;
    ll b = 1, a = 2;
    bool f = true;
    if(n == 0){ co(0); return 0;}
    while(1){
        if(n == 0) break;
        ll r = n % a;
        if(r < 0) r *= -1;
        ans.push_back('0'+r/b);
        if(f) n -= r, f = false;
        else n += r, f = true;
        b *= 2, a *= 2;
    }
    reverse(ALL(ans));
    co(ans);

    return 0;
}

