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

Vl A(45), B(45);

int main() {
    ll a, b; cin >> a >> b;
    b++;
    ll r = 2, l = 1;
    Rep(i, 0, 40){
        A[i]+=(a/r)*l;
        if(a%r > l) A[i]+=a%r-l;
        r*=2; l *= 2;
    }
    r = 2, l = 1;
    Rep(i, 0, 40){
        B[i]+=(b/r)*l;
        if(b%r > l) B[i]+=b%r-l;
        r*=2; l *= 2;
    }
    Rep(i, 0, 40){
        B[i]-=A[i];
        B[i]%=2;
    }
    ll u = 1;
    ll ans = 0;
    Rep(i, 0, 40){
        if(B[i]){
            ans += u;
        }
        u *= 2;
    }
    
    co(ans);

    return 0;
}
