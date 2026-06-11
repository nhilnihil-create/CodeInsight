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
    ll a, b;    cin >> a >> b;
    queue<ll> que;
    if(a&1){
        que.push(a);
        a = min(a+1, b);
    }
    if(b%2==0){
        que.push(b);
        b = max(b-1, a);
    }
    ll ans = ((b-a+1)/2)%2;
    
    while(!que.empty()){
        //cout << que.front() << endl;
        ans = ans^que.front();
        que.pop();
    }
    cout << ans << endl;
}