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

// 愚直にやると計算量が大きい

int main() {
    string s; cin >> s;
    string t = {};
    rep(i, 0, sz(s)){
        if(s[i]=='B' && s[i+1]=='C'){
            t.push_back('D');
            i++;
        }
        else t.push_back(s[i]);
    }
    ll cnta = 0, ans = 0;
    rep(i, 0, sz(t)){
        if(t[i]!='A'&&t[i]!='D'){
            cnta = 0;
        }else{
            if(t[i]=='A') cnta++;
            if(t[i]=='D') ans += cnta;
        }
    }
    co(ans);

    return 0;
}
