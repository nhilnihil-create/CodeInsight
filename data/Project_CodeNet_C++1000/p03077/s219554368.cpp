#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,n) for (int i=0; i < (n); ++i)
using ll = long long ;
using namespace std;
const int INF = 1001001001;

ll min(ll a,ll b){
    return (a<=b) ? a : b ;
}

ll max(ll a,ll b){
    return (a<=b) ? b : a ;
}


int main() {

    ll n,a,b,c,d,e ;
    cin >> n >> a >> b >> c >> d >> e ;
    
    vector<ll> num(6) ;
    num[0] = n ;

    ll time = 0 ;
    ll MIN = min({a,b,c,d,e});
    time = (n+MIN-1)/MIN ;
    cout << time+4 << endl ;

    return 0 ;
}
