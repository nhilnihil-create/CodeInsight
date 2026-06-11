#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    string s;
    cin >> s;
    ll res = 700;
    for (auto c : s) {
        if (c == 'o') res += 100;
    }
    cout << res << endl;
}
