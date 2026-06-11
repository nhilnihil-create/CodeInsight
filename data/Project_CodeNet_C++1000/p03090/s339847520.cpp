#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ll n;   cin >> n;
    vector<pair<ll, ll>> v;
    if(n%2){
        rep(i, n-1) v.emplace_back(i+1, n);
        n -= 1;
    }
    rep(i, n){
        FOR(j, i+1, n){
            if(j==n-1-i) continue;
            v.emplace_back(i+1, j+1);
        }
    }
    
    cout << v.size() << endl;
    for(auto x: v) cout << x.first << ' ' << x.second << endl;;
}
