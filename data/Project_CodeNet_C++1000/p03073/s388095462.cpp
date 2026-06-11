#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int index0 = 0, index1 = 0;
    string s;
    cin >> s;
    rep(i, s.size()) {
        if (s[i] != '0' && i % 2 == 0)
            index0++;
        if (s[i] != '1' && i % 2 == 1)
            index0++;
        if (s[i] != '1' && i % 2 == 0)
            index1++;
        if (s[i] != '0' && i % 2 == 1)
            index1++;
    }
    cout << min(index0, index1) << endl;
    return 0;
}