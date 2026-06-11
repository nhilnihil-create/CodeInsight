#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> cnt;
    vector<string> s(n);
    int i = 0;
    for (string x; n--; cnt[x]++) {
        cin >> x;
        s.at(i++) = x;
    }

    int m;
    cin >> m;
    for (string x; m--; cnt[x]--) cin >> x;

    int r = 0;
    for (int i = 0; i < s.size(); i++) {
        if (r < cnt[s.at(i)]) r = cnt[s.at(i)];
    }

    cout << r << endl;

    return 0;
}
