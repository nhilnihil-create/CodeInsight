#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N, X;
    cin >> N >> X;
    vector<int> m(N, 0);
    int sum_m = 0;
    for (int i = 0; i < N; ++i) {
        cin >> m[i];
        sum_m += m[i];
    }

    int ans = N;
    ans += (X - sum_m) / (*min_element(m.begin(), m.end()));
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
