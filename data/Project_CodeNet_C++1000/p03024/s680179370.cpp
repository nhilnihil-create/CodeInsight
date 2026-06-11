#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') cnt++;
    }
    if (15 - n + cnt < 8) cout << "NO" << endl;
    else cout << "YES" << endl;
}