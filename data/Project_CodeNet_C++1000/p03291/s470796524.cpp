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
    ll p[100005] = {1}, a = 0, b = 0, c[100005] = {}, d[100005] = {}, z = 0;
    for (int i = 1; i <= 100002; i++) p[i] = p[i - 1] * 3 % mod;
    cin >> s; s = 'X' + s;
    for (int i = (int)s.length() - 1; i; i--) c[i] = c[i + 1] + (s[i] == 'C'), d[i] = d[i + 1] + (s[i] == '?');
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == 'B' || s[i] == '?') {
            z = (z + (p[b] * a + (b ? p[b - 1] : 0) * b) % mod * ((p[d[i + 1]] * c[i + 1] + (d[i + 1] ? p[d[i + 1] - 1] : 0) * d[i + 1]) % mod)) % mod;
        }
        if (s[i] == 'A') a++;
        if (s[i] == '?') b++;
    }
    cout << z;
}
