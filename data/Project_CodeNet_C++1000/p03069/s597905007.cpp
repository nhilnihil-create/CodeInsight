#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> vtL(n + 1, 0);
    vector<int> vtR(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        vtL[i + 1] = vtL[i];
        if (s[i] == '#') vtL[i + 1]++;

        if (n - 2 - i < 0) continue;
        vtR[n - 2 - i] = vtR[n - 1 - i];
        if (s[n - 1 - i] == '.') vtR[n - 2 - i]++;
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, vtL[i] + vtR[i]);
    }
    cout << ans << endl;
    return 0;
}
