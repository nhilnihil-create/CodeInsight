#include<bits/stdc++.h>

using namespace std;


void solve() {
    long long X, Y; cin >> X >> Y;
    
    long long ans = 0;
    long long tmp = X;
    while (tmp <= Y) {
        ans++;
        tmp *= 2;
    }

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}