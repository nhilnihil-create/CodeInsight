#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    string s; cin >> s;
    ll k; cin >> k;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') k--;
        else {
            cout << s[i] << endl;
            return 0;
        }
        if (k == 0) {
            cout << "1" << endl;
            return 0;
        }
    }
}