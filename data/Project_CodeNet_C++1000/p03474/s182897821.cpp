#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int a, b; cin >> a >> b;
    string s; cin >> s;
    bool can = true;
    for (int i = 0; i < a + b + 1; i++) {
        if (i == a) {
            if (s[i] != '-') {
                can = false;
                break;
            }
        }
        else {
            if (!(0 <= s[i] - '0' && s[i] - '0' <= 9)) {
                can = false;
                break;
            }
        }
    }

    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;        
    return 0;
}