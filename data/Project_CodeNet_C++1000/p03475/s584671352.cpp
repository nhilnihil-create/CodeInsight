#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> c(n - 1), s(n - 1), f(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> c[i] >> s[i] >> f[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int now = 0;
        for (int j = i; j < n - 1; j++) {
            if (now < s[j]) {
                now = s[j] + c[j];
            } else if (now % f[j]) {
                now += f[j] - now % f[j] + c[j];
            } else {
                now += c[j];
            }
        }
        cout << now << endl;
    }
    cout << 0 << endl;
    return 0;
}