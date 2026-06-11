#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
    ll X, Y;
    cin >> X >> Y;
    int ans = 1;
    while (X * 2 <= Y) {
        X *= 2;
        ++ans;
    }
    cout << ans << endl;
}

