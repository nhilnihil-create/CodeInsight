#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))


int main(){
    ll n;   cin >> n;
    vector<ll> div;
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            div.push_back(i);
            if(n/i!=i) div.push_back(n/i);
        }
    }
    sort(ALL(div));
  
    ll sum=0;
    for(auto x: div){
        ll obj = n/x-1;
        if(obj<1) continue;
        if(n/obj == n%obj) sum += obj;
    }
    cout << sum << endl;
}