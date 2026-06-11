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
    ll y;
    cin >> n >> y;

    for(int i = 0; i <= 2000; i++){
        for(int j = 0; j <= 2000; j++){
            ll tmp = y - i*10000 - j*5000;
            if(tmp < 0) continue;
            if(i + j + tmp/1000 == n){
                cout << i << " " << j << " " << tmp/1000 << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;

    return 0;
}