#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N.length(); i++) {
        ans += N[i] == '2';
    }
    cout << ans << endl;
    return 0;
}