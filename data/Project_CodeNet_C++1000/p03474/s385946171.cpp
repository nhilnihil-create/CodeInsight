#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    int a, b; cin >> a >> b;
    string s; cin >> s;
    bool can = true;
    for (int i = 0; i < a; i++) {
        int tmp = s[i] - '0';
        if (!(0 <= tmp && tmp <= 9)) can = false;
    }
    if (s[a] != '-') can = false;
    for (int i = a + 1; i < a + b + 1; i++) {
        int tmp = s[i] - '0';
        if (!(0 <= tmp && tmp <= 9)) can = false;
    }
    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}