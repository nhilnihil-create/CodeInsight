#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    ll N,X;
    cin>>N>>X;
    ll max = 0;
    rep(i, N){
        ll x; cin>>x;
        max = __gcd(abs(X-x), max);
    }

    cout << max << endl;
}
