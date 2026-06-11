#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int w;

    cin >> s >> w;
    string t;
    for (int i = 0; i < s.length(); i += w) {
        t += s[i];
    }
    cout << t << endl;
    return 0;
}
