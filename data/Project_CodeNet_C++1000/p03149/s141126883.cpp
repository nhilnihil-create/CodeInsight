#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    for (int i = 0; i < 4; i++) {
        char c;
        cin >> c;
        s += c;
    }
    sort(s.begin(), s.end());
    if (s == "1479") cout << "YES" << endl;
    else cout << "NO" << endl;
}