#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    ll n; cin >> n;
    map<ll, ll> m;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        m[a]++;
    }

    ll ans = 0;
    for(auto p : m){
        if(p.first != p.second){
            if(p.second > p.first){
                ans += p.second - p.first;
            }else{
                ans += p.second;
            }
        }
    }
    cout << ans << endl;
}
