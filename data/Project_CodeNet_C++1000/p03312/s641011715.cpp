#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define debug(v) cout << #v<< ": " << v <<endl;
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;
ll M = 1000000007;

int main(){
    ll n; cin >> n;
    vll a(n);
    rep(i, 0, n){
        cin >> a[i];
    }    
    vll ac(n+1);
    ac[0] = 0;
    ll s = 0;
    rep(i, 1, n+1){
        s += a[i-1];
        ac[i] = s;
    }
    ll mn = INF;
    ll lc = 1, rc = 3;
    rep(i, 2, n-1){
        while(abs(ac[i] - ac[lc] - (ac[lc])) > abs(ac[i] - ac[lc+1] - ac[lc+1])){
            lc++;
        }
        while(abs(ac[n] - ac[rc] - (ac[rc] - ac[i])) > abs(ac[n] - ac[rc+1] - (ac[rc+1] - ac[i]))){
            rc++;
        }
        ll x = max(max(ac[lc], ac[i]-ac[lc]), max(ac[rc]-ac[i], ac[n]-ac[rc]));
        ll y = min(min(ac[lc], ac[i]-ac[lc]), min(ac[rc]-ac[i], ac[n]-ac[rc]));
        chmin(mn, x-y);
    }
    prtl(mn);
}

