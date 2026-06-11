#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    long N;
    cin>>N;
    long ans;
    rep(i, N){
        long A; cin>>A;
        if(i == 0) ans = A;
        else ans = __gcd(ans, A);
    }

    cout << ans << endl;
}