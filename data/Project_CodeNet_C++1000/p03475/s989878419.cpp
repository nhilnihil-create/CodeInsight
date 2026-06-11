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

int main() {
    ll n; cin >> n;
    Vl c(n-1), s(n-1), f(n-1);
    rep(i, 0, n-1){
        cin >> c[i] >> s[i] >> f[i];
    }
    Vl ans;
    rep(i, 0, n){
        ll t = 0;
        rep(j, i, n-1){
            // if(i == 0) cout << t << endl;
            if(t <= s[j]) t = s[j];
            else if(t%f[j] == 0){}
            else t = t + f[j] - t%f[j];
            t += c[j];
        }
        ans.push_back(t);
    }
    rep(i, 0, sz(ans)) co(ans[i]);

    return 0;
}
