#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> S(h);
    for (auto & s : S) cin >> s;

    bool gok = true;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (S[i][j] == '.') continue;
            bool ok = false;
            if (i > 0 && S[i-1][j] == '#') ok |= true;
            if (i < h-1 && S[i+1][j] == '#') ok |= true;
            if (j > 0 && S[i][j-1] == '#') ok |= true;
            if (j < w-1 && S[i][j+1] == '#') ok |= true;
            if (!ok) {
                gok = false;
                break;
            }
        }
        if (!gok) break;
    }

    if (gok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
