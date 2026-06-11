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
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ll n;   cin >> n;
    vector<ll> isPrime(55'556, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=55'555; i++){
        if(!isPrime[i]) continue;
        for(int j=2*i; j<=55'555; j+=i){
            isPrime[j] = false;
        }
    }
    vector<ll> res;
    rep(i, 55'556){
        if(isPrime[i] && i%10==3) res.push_back(i);
    }

    
    rep(i, n){
        cout << res[i];
        if(i<n-1)   cout << ' ';
        else cout << endl;
    }
}
