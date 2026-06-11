#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,h,w;
    cin >> n >> h >> w;
    ll tate=n-h+1,yoko=n-w+1;
    cout << tate*yoko << endl;
}