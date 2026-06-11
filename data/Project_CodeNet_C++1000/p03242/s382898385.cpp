#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    string n; cin >> n;
    for (int i = 0; i < n.size(); ++i) {
        if (n[i] == '1') {
            cout << '9';
        }
        else {
            cout << '1';
        }
    }
    cout << endl;
}