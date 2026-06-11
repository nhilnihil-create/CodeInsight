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

    if(a.at(0) != 0){
        cout << -1 << endl;
        return 0;
    }
    REP(i, n - 1){
        if(a.at(i) < a.at(i + 1) && a.at(i + 1) - a.at(i) > 1){
            cout << -1 << endl;
            return 0;
        }
    }

    ll ans = 0;
    REP(i, n){
        if(i == n - 1 || a.at(i) + 1 != a.at(i + 1)){
            ans += a.at(i);
        }
    }
    cout << ans << endl;
    return 0;
}
