#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    ll t[N + 1], x[N + 1], y[N + 1];
    t[0] = 0;
    x[0] = 0;
    y[0] = 0;
    for(ll i = 1; i < N + 1; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }

    for(ll i = 1; i < N + 1; i++) {
        ll dist = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
        ll td = t[i] - t[i - 1];
        if(!(td - dist >= 0 && (td - dist) % 2 == 0)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}