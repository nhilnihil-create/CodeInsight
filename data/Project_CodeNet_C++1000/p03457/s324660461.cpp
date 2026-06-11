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
    ll x, y;
    x = y = 0;
    ll crt;
    crt = 0;
    bool ok = true;
    for(int i = 0; i < n; i++){
        int t, a, b;
        cin >> t >> a >> b;
        if(abs(x-a)+abs(y-b) > t-crt){
            ok = false;
        }
        else if(abs(x-a)+abs(y-b) < t-crt){
            if((abs(x-a)+abs(y-b)) % 2 != 0){
                if(t-crt % 2 == 0) ok = false;
            }
            else{
               if(t-crt % 2 != 0) ok = false;
            }
        }
        x = a;
        y = b;
        crt = t;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}