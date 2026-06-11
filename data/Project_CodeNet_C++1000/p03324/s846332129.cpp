#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int D, N;
    cin >> D >> N;
    int seq1 = 0, seq2 = 0, ans1, ans2;
    if (D == 0) {
        int ans = N;
        if (N == 100)
            ans += 1;
        cout << ans << endl;
        return 0;
    } else if (D == 1) {
        int ans = N * 100;
        if (N == 100)
            ans += 100;
        cout << ans << endl;
        return 0;
    } else {
        int ans = N * 10000;
        if (N == 100)
            ans += 10000;
        cout << ans << endl;
        return 0;
    }
}