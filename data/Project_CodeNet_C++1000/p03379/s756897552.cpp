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
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    for(ll i = 0; i < n; i++){
        if(b[n/2] <= a[i]) cout << b[(n/2)-1] << endl;
        else cout << b[n/2] << endl;
    }

    return 0;
}
