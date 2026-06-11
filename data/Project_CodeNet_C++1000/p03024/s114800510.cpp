#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    string s;
    cin >> s;
    int ok = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'o') ok++;
    }
    cout << (8 <= 15 - s.size() + ok ? "YES" : "NO") << endl;
    return 0;
}