#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,x;
    cin >> n >> x;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (ans <= x) {
            ans = ans*2;
        }else {
            ans = ans + x;
        }
    }
    cout << ans << endl;
    return 0;
}