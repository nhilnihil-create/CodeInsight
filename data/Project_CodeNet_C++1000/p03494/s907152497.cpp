#include <bits/stdc++.h>
using namespace std;

int main() {
    long n, ans = 0;
    cin >> n;
    bool odd = false;
    vector<long> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data.at(i);
        if (data.at(i) % 2 == 1) {
            odd = true;
            break;
        }
    }
    while (odd != true) {
        for (int i = 0; i < n; i++) {
            data.at(i) /= 2;
            if (data.at(i) % 2 == 1) {
                odd = true;
                ans++;
                break;
            }
        }
        if (odd == false) {
            ans++;
        }
    }
    cout << ans << endl;
}