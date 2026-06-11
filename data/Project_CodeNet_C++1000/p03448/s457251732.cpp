#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    a *= 500;
    b *= 100;
    c *= 50;
    int ans = 0;
    for(int ai = a; ai >= 0; ai -= 500) {
        if(ai > x) continue;
        for(int bj = b; bj >= 0; bj -= 100) {
            if(ai + bj > x) continue;
            if(x - ai - bj <= c) ans++;
        }
    }
    cout << ans << endl;
}