#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = (int)s.length(), c = n;
    bool y = 0;
    s = 'c' + s;
    if (s[n] == '1' || s[1] == '0') y = 1;
    for (int i = 1; i < n; i++) if (s[i] != s[n - i]) y = 1;
    if (y) {cout << -1; return 0;}
    for (int i = n - 1; i; i--) {
        cout << c << ' ' << i << '\n';
        if (s[i] == '1') c = i;
    }
}
