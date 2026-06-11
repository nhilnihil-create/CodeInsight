#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll x,y;
    cin >> x >> y;
    ll cnt=0;
    while(x<=y){
        x*=2;
        cnt++;
    }
    cout << cnt << endl;
}