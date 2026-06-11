#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

int main(){

    ll n;
    cin >> n;
    ll a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    ll min_p = min({a, b, c, d, e});
    ll ans = ((n + min_p - 1) / min_p) + 4;
    cout << ans << endl;
    return 0;
}