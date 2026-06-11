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

    ll x, y;
    cin >> x >> y;

    ll ans = 1;
    ll v = x;
    while(v <= y){
        v *= 2;
        if(v <= y){
            ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}
