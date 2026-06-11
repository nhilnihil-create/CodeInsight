#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    ll N; cin>>N;
    ll min = 10e15;
    rep(i, 5){
        ll x; cin>>x;
        min = std::min(x, min);
    }

    cout << (ll)ceil(N/(double)min) + 4 << endl;
}
