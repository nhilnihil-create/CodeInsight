#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=b-1; (ll)(a)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string YES[2] = {"NO", "YES"};
string yes[2] = {"No", "Yes"};

int main(){
    ll n;   cin >> n;
    vector<ll> v(n, 0);
    rep(k, n){
        ll x=k+1;
        for(int i=1; i*i<=x; i++){
            if(x%i==0){
                v[k] += 1;
                if(x/i!=i) v[k] += 1;
            }
        }
    }
    ll res=0;
    rep(i, n){
        if(i%2) continue;
        res += v[i]==8;
    }
    cout << res << endl;
}
