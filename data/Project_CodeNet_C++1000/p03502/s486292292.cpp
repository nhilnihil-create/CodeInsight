#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

ll func(ll n){
    ll res = n%10;
    while(n/10 != 0){
        n /= 10;
        res += n%10;
    }
    return res;
}
int main(){

    ll n;
    cin >> n;
    if(n % func(n) == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}