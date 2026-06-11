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

Vl v;

void bf(){
    v.push_back(1);
    ll r = 6;
    while(1){
        if(r > 100000) break;
        v.push_back(r);
        r *= 6;
    }
    r = 9;
    while(1){
        if(r > 100000) break;
        v.push_back(r);
        r *= 9;
    }
}

int main() {
    bf();
    sort(ALL(v), greater<ll>());

    ll n; cin >> n;
    Vl dp(n+1, INF);
    dp[0] = 0;

    rep(i, 1, n+1){
        rep(j, 0, sz(v)){
            if(i-v[j]>=0) chmin(dp[i], dp[i-v[j]]+1);
        }
    }

    co(dp[n]);

    return 0;
}
