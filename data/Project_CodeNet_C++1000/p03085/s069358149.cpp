#include <bits/stdc++.h>
using namespace std;

int main() {
    string mp = "ACGT";
    char c;

    cin >> c;
    for (int i = 0; i < int(mp.size()); i++) {
        if (c != mp[i]) continue;
        cout << mp[int(mp.size()) - i - 1] << endl;
    }

    return 0;
}

