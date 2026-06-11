#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll x, y;
    cin >> x >> y;
    
    ll t = x, ans = 0;
    while (t <= y) {
        ans++;
        t *= 2;
    }
    
    cout << ans << endl;
    
    return 0;
}
