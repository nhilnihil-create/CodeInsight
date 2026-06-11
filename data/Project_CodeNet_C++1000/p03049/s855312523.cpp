#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = b-1; i >= a; i--)
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
    ll n; cin >> n;
    Vs s(n);
    rep(i, 0, n) cin >> s[i];

    ll ans = 0;
    ll a = 0, ba = 0, b = 0;
    rep(i, 0, n){
        rep(j, 0, sz(s[i])-1){
            if(s[i][j]=='A'&&s[i][j+1]=='B') ans++;
        }
        if(s[i][0] == 'B' && s[i][sz(s[i])-1] == 'A') ba++;
        else if(s[i][0] == 'B') b++;
        else if(s[i][sz(s[i])-1] == 'A') a++;
    }
    if(a && ba) ans++, a--;
    if(b && ba) ans++, b--;
    ans += max(0LL, min(a,b));
    ans += max(ba-1, 0LL);
    co(ans);

    return 0;
}


