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

    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }

    int ans = 0;
    int v = 0;
    for(int i = 0; i < n; i++){
        if(v >= h[i]) v = h[i];
        else{
            ans += h[i] - v;
            v = h[i];
        }
    }

    cout << ans << endl;
    
    return 0;
}