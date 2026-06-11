#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    vector<int> h(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    int maxHeight = 100;
    vector<int> f(N, 0);
    int ans = 0;
    for (int i = 0; i < maxHeight; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j == 0 && h[j] > 0) {
                ++ans;
            }
            else if (h[j - 1] == 0 && h[j] > 0) {
                ++ans;
            }
        }
        for (int j = 0; j < N; ++j) {
            if (h[j] > 0) {
                h[j] -= 1;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
