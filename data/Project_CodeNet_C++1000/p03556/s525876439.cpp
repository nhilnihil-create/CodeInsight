#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    ll n;
    cin >> n;

    ll i = 1;
    ll ans;
    while(i*i <= n){
        ans = i*i;
        i++;
    }
    cout << ans << endl;
    
    return 0;
}