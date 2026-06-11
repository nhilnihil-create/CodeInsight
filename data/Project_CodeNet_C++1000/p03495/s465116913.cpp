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
    vector<ll> v(200000);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v[a]++;
    }
    ll ans = 0;
    sort(v.rbegin(), v.rend());
    for(int i = k; i < (int)v.size(); i++){
        if(v[i] == 0) break;
        ans += v[i];
    }
    cout << ans << endl;
    return 0;
}
