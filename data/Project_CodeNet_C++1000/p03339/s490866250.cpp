#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int rev = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == 'E') rev++;
    }
    int min = rev;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == 'W') rev++;
        if (s[i] == 'E') rev--;
        min = (min > rev) ? rev : min;
    }
    cout << min << endl;
    return 0;
}