#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    ll a, b, k;
    cin >> a >> b >> k;

    int l;
    for(ll i = 0; i < k; i++){
        if(a + i > b) break;
        cout << a + i << endl;
        l = a+ i;
    }
    if(l > b - k){
        for(ll i = l+1; i <= b; i++){
            cout << i << endl;
        }
    }
    else{
        for(ll i = 0; i < k; i++){
            cout << b - k + 1 + i << endl;
        }
    }
    return 0;
}