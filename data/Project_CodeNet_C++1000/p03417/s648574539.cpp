#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ll n,m;
    cin >> n >> m;
    ll ans = 0;
    ll a = min(n,m);
    ll b = max(n,m);
    ans = (b-2)*(a-2);
    cout << abs(ans) << endl;
}