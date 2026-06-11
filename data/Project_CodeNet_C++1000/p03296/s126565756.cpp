#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n){
        cin >> a.at(i);
    }
    ll ans = 0;
    for(ll i = 1; i < n; ++i){
        if(a.at(i) == a.at(i - 1)){
            ans++;
            a.at(i) = - i;
        }
    }
    cout << ans << endl;
    return 0;
}
