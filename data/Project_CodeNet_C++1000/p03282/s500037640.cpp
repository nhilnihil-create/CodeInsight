#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    ll k;
    cin >> s;
    cin >> k;
    if (s.size() >= k) {
        for (ll i = 0; i < k; i++) {
            if (s.at(i) - '0' != 1) {
                cout << s.at(i) << endl;
                return 0;
            }
        }
        cout << 1 << endl;
        return 0;
    } else {
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) - '0' != 1) {
                cout << s.at(i) << endl;
                return 0;
            }
        }
    }
}