#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(17) << res << endl;
 
int main() {
    string s;
    cin >> s;
    auto res = 0;
    for (auto c : s) {
        if (c == '+') {
            ++res;
        } else {
            --res;
        }
    }
    cout << res << endl;
}
