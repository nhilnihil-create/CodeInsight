#include "bits/stdc++.h"

using namespace std;

void Main() {
    int a, b;
    cin >> a >> b;

    vector<int> h(1000, 0);
    for (int i = 0; i < h.size(); ++i) {
        if (i == 0) {
            h[i] = 0;
        }
        else {
            h[i] = i * (i + 1) / 2;
        }
    }

    int ans = 0;
    for (int i = 2; i < h.size(); ++i) {
        if (h[i - 1] - a == h[i] - b) {
            ans = h[i] - b;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
