#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, k, z = 0;
    vector<int> a = {0};
    string s;
    cin >> n >> k >> s;
    if (s[0] == '0') a.push_back(0);
    int l = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] != s[i - 1]) {
            a.push_back(i - l);
            l = i;
        }
    }
    for (int i = 0; i < 300005; i++) a.push_back(0);
    for (int i = 1; i < a.size(); i++) a[i] += a[i - 1];
    for (int i = 1; i <= n + 1; i++) {
        if (i % 2) {
            z = max(z, a[i + k + k] - a[i - 1]);
        }
    }
    cout << z;
}
