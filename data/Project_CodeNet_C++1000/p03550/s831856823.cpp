#include "bits/stdc++.h"

using namespace std;

int N, Z, W;
vector<int> a;

void Main() {
    cin >> N >> Z >> W;
    a = vector<int>(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    if (N == 1) {
        cout << abs(W - a[0]) << endl;
        return;
    }
    int diffLast2 = abs(a[N - 2] - a[N - 1]);
    int diffYvsLast = abs(a[N - 1] - W);
    int ans = max(diffLast2, diffYvsLast);
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
