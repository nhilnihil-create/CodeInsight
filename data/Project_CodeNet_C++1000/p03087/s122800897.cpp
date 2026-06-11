#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> pref(n+1, 0);

    for (int i = 1; i < n; i++) {
        bool flag = false;
        if (s[i - 1] == 'A' && s[i] == 'C')
            flag = true;
        pref[i] = pref[i - 1] + flag;
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        cout << pref[r] - pref[l] << endl;
    }
}