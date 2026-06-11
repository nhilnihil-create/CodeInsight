#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll MOD = 1e9+7;
const static ll INF = 1e14;


int main() {
    ll a, b; cin >> a >> b;
    ll ans = a-1;
    if(b >= a) ans++;
    cout << ans << endl;

}