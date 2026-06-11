#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int cnt[3] = {0};
    rep(i, N) {
        int t;
        cin >> t;

        if (t <= A)
            cnt[0]++;
        else if (t <= B)
            cnt[1]++;
        else
            cnt[2]++;
    }

    cout << min({cnt[0], cnt[1], cnt[2]}) << endl;

    return 0;
}
