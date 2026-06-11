#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int main(){
    ll n ;
    cin >> n ;
    vector<ll> a(n) , b(n) ;
    ll tota = 0 ;
    ll totb = 0 ; 
    rep(i, n) cin >> a[i] ;
    rep(i, n) cin >> b[i] ;
    rep(i, n) tota += a[i] ;
    rep(i, n) totb += b[i] ;
    if(tota < totb) {
        cout << -1 << endl ;
        return 0 ; 
    }
    priority_queue<ll, vector<ll>> que ;
    ll mns = 0 ;
    ll ans = 0 ; 
    rep(i, n){
        if(b[i] > a[i]){
            mns += b[i] - a[i] ;
        }
        else {
            que.push(a[i] - b[i]) ;
            ans++ ; 
        }
    }
    while(1){
        if(mns <= 0 ){
            break ; 
        }
        ll t = que.top() ;
        que.pop() ;
        mns -= t ; 
        ans-- ;
    }
    cout << n - ans << endl ; 
}
