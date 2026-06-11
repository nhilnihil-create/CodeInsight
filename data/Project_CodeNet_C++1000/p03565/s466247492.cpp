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
    string s, t; cin >> s >> t;
    if(sz(s) < sz(t)){
        co("UNRESTORABLE");
        return 0;
    }
    for(int i = sz(s)-sz(t); i >= 0; i--){
        bool f = true;
        rep(j, 0, sz(t)){
            if(s[i+j] == '?'){
            }else{
                if(s[i+j] != t[j]) f = false;
            }
        }
        if(f){
            rep(j, 0, sz(t)){
                s[i+j] = t[j];
            }
            break;
        }
        if(i == 0){
            co("UNRESTORABLE");
            return 0;
        }
    }
    rep(i, 0, sz(s)){
        if(s[i] == '?') s[i] = 'a';
    }
    co(s);

    return 0;
}
