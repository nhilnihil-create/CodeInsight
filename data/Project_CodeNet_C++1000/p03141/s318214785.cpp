#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main(){
    ll n ; cin >> n;
    vector<pair<ll,ll>> hpns(n);
    rep(i,n){
        ll a,b ; cin >> a >> b;
        hpns.at(i).first = a;
        hpns.at(i).second = b;
    }
    std::sort(hpns.begin(), hpns.end(), [](const pair<ll,ll> a, const pair<ll,ll> b) {
        return a.first + a.second > b.first + b.second;
    });
    ll ans = 0;

    rep(i,n){
        if(!(i%2)) ans += hpns.at(i).first+hpns.at(i).second;
    }
    rep(i,n){
        ans -= hpns.at(i).second;
    }
    cout << ans << endl;

}
