#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    ll x, y; cin >> x >> y;
    int cnt = 0;
    while(x <= y) {
        x *= 2;
        cnt++;
    }
    cout << cnt;
}
