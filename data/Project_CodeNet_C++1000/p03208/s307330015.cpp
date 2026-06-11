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

    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    ll ans = LINF;
    for(int i = 0; i < n-k+1; i++){
        ans = min(ans, h[i+k-1] - h[i]);
    }
    cout << ans << endl;
    return 0;
}