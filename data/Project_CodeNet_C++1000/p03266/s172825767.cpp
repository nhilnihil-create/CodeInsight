#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    long n, k, cnt = 0, even = 0, ans;
    cin >> n >> k;
    rep(i, n) {
        if((i + 1) % k == 0) cnt++;
        else if((i + 1) % k == k / 2) even++;
    }
    if(k % 2) ans = pow(cnt, 3);
    else ans = pow(cnt, 3) + pow(even, 3);
    cout << ans << endl;
}