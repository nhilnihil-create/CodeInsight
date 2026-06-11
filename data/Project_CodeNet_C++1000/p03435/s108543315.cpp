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
    Vl c1(3), c2(3), c3(3);
    rep(i, 0, 3) cin >> c1[i];
    rep(i, 0, 3) cin >> c2[i];
    rep(i, 0, 3) cin >> c3[i];

    ll a = c1[0]-c1[1], b = c1[1]-c1[2];
    if(c2[0]-c2[1]==a && c2[1]-c2[2]==b && 
    c3[0]-c3[1]==a && c3[1]-c3[2]==b ) co("Yes");
    else co("No");

    return 0;
}
