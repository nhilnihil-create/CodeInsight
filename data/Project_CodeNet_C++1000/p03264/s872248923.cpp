#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int K,ans;
    cin >> K;
    if(K%2) {
        ans = (K/2) * (K/2+1);
    } else {
        ans = (K/2) * (K/2);
    }

    cout << ans << endl;
    return 0;
}
