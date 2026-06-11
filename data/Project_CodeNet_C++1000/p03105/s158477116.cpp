#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    int A, B, C;

    cin >> A >> B >> C;

    ll ans = 0;



    for (ll i = 0; i < B/A; i++) {
        if (ans >= C) break;
        ans++;
    }
    
    
    
    cout << ans << endl;
    
    return 0;
}