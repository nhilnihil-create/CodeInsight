#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {
    int N, T, A;
    cin >> N >> T >> A;
    int H[N];
    rep(i, N) cin >> H[i];

    float min_temp = 1000000;
    int ans = -1;

    for (int i = 0; i < N; ++i) {
        if (min_temp >= abs(T-H[i]*0.006-A)) {
            min_temp = abs(T-H[i]*0.006-A);
            ans = i+1;
        }
    }

    cout << ans << endl;

    return 0;
}