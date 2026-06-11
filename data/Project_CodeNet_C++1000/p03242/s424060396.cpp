#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    string n;
    cin >> n;
    for (int i = 0; i < n.length(); ++i)
    if (n[i] == '9') n[i] = '1';
    else if (n[i] == '1') n[i] = '9';
    cout << n;
}