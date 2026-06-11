#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll n, m; cin >> n >> m;
    ll a = (n-m)*100, b = 1900*m, c = pow(2, m), d = (a+b)*c;
    cout << d << endl;
    return 0;
}