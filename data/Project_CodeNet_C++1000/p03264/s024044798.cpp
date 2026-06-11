#include <bits/stdc++.h>
using namespace std;

int main() {
    int K,ans;
    cin >> K;
    if (K % 2 == 0) {
        ans = K/2 * K/2;
    } else {
        ans = (K+1)/2 * (K-1)/2;
    }
    cout << ans << endl;
}
