#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
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

int main() {
    string s; cin >> s;
    ll l = 0, r = sz(s)-1;
    ll cnt = 0;
    while(l < r){
        if(s[l] == s[r]){
            l++;
            r--;
        }else if(s[l] == 'x' && s[r] != 'x'){
            l++;
            cnt++;
        }else if(s[l] != 'x' && s[r] == 'x'){
            r--;
            cnt++;
        }else {
            co(-1);
            return 0;
        }
    }
    co(cnt);

    return 0;
}


