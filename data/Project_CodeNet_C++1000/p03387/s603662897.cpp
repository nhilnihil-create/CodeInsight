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

    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    int ans = 0;
    if(v[0] % 2 != v[1] % 2){
        ans++;
        v[0]++;
        v[2]++;
    }

    ans += v[2] - v[1] + (v[1] - v[0]) / 2;
    cout << ans << endl;

    return 0;
}
