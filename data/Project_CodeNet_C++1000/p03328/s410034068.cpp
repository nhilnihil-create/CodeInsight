#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int bn = b-a;
    int ans = 0;
    for (int i = 1; i <= bn; i++) {
        ans += i;
    }
    ans -= b;
    cout << ans << endl;
}