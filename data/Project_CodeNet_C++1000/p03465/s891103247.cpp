#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bitset<4000010> dp;

int main() {
    int N;
    cin >> N;
    dp[0] = 1;
    int s = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        dp |= dp << x;
        s += x;
    }

    int mx = -1;
    int ans = 0;
    for (int i = 0; i <= 4000000; i++) {
        if (dp[i]) {
            if (mx < min(i, s - i)) {
                ans = i;
                mx = min(i, s - i);
            }
        }
    }
    cout << s - ans << endl;
}