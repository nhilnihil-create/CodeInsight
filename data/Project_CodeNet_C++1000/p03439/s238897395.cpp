#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = b-1; i >= a; i--)
// #define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
// #define endl "\n"
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

string s[110000];

int main() {
    ll n; cin >> n;


    cout << 0 << endl;
    cin >> s[0];
    if(s[0] == "Vacant") return 0;

    cout << n-1 << endl;
    cin >> s[n-1];
    if(s[n-1] == "Vacant") return 0;

    ll l = 0, r = n-1;

    while(r-l > 1){
        ll h = (l+r)/2;
        cout << h << endl;
        cin >> s[h];
        if(s[h] == "Vacant") return 0;
        if((h-l)%2 == 0){
            if(s[l] != s[h]) r = h;
            else l = h;
        }else{
            if(s[l] == s[h]) r = h;
            else l = h;
        }
    }


    return 0;
}
 
 
