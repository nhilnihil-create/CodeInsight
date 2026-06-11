#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int r = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') r++;
        else b++;
    }
    cout << (r > b ? "Yes" : "No") << endl;
}