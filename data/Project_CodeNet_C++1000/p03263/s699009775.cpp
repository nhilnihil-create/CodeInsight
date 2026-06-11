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
    ll h, w; cin >> h >> w;
    Vl y, x, Y, X;
    vector<Vl> a(h, Vl(w));
    rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
    rep(i, 0, h){
        rep(j, 0, w-1){
            if(a[i][j]%2 !=0){
                a[i][j+1]++;
                y.push_back(i+1);
                x.push_back(j+1);
                Y.push_back(i+1);
                X.push_back(j+2);
            }
        }
    }
    rep(i, 0, h-1){
        if(a[i][w-1]%2 != 0){
            a[i+1][w-1]++;
            y.push_back(i+1);
            x.push_back(w);
            Y.push_back(i+2);
            X.push_back(w);
        }
    }
    co(y.size());
    rep(i, 0, sz(y)){
        co(y[i] << " " << x[i] << " " << Y[i] << " " << X[i]);
    }

    return 0;
}
