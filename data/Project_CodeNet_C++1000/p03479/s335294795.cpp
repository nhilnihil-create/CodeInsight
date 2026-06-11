#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll x, y; cin >> x >> y;
    int cnt = 1;
    while(true) {
        x *= 2;
        if (x <= y) cnt ++;
        else break;
    }
    cout << cnt << endl;
}