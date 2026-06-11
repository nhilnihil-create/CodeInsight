#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < (int)S.length(); i++)
    {
        if (S[i] == '0')
        {
            ans++;
        }
    }
    ans = min(ans, (int)S.length()-ans) * 2;
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}