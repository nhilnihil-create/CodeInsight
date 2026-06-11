#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int lose = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'x') lose++;
    }
    if (lose > 7) cout << "NO" << endl;
    else cout << "YES" << endl;
}