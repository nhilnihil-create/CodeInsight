#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    vector<int> V(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }
    for (int i = 0; i < N; ++i) {
        int c;
        cin >> c;
        V[i] -= c;
    }
    sort(V.begin(), V.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (V[i] > 0) {
            ans += V[i];
        }
        else {
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
