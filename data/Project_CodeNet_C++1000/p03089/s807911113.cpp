#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
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




////////////////////////////////////////////////////////


int main() {
    ll n; cin >> n;
    Vl b(n+1), ans;
    Rep(i, 1, n) cin >> b[i];
    bool f;
    rep(i, 0, n){
        bool f = true;
        for(int j = sz(b)-1; j >= 1; j--){
            if(j == b[j]){ 
                ans.push_back(j);
                b.erase(b.begin()+j);
                // ////
                // rep(i, 1, sz(b)) cout << b[i] << " ";
                // coel;
                f = false;
                break;
            }
        }
        if(f){
            co(-1);
            return 0;
        }
    }
    reverse(ALL(ans));
    rep(i, 0, n) co(ans[i]);

    return 0;
}
