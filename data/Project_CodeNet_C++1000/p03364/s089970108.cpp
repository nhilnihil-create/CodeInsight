#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<string>s(N);
    for (int i = 0; i < N; ++i) {
        cin >> s[i];
        s[i] = s[i] + s[i];
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        int flag = 1;
        for (int j = 1; j < N; ++j) {
            for (int k = 0; k < j; ++k) {
                if(s[k][i+j] != s[j][i+k]) flag = 0;
            }
        }
        ans += flag;
    }
    ans *= N;
    cout << ans << "\n";
    return 0;
}