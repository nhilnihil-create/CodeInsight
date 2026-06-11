#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    string s; cin >> s;
    if (s[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }
    int idx = -1;
    int cCount = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (!islower(s[i])) {
            if (s[i] == 'C') {
                cCount++;
                idx = i;
                if (cCount > 1) {
                    cout << "WA" << endl;
                    return 0;
                }
            }
            else {
                cout << "WA" << endl;
                return 0;
            }
        }
    }
    if (idx > 1 && idx < s.size() - 1) {
        cout << "AC" << endl;
    }
    else {
        cout << "WA" << endl;
    }
}
