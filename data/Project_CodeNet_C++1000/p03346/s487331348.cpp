#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];

    vector<int> positions(N);
    for (int i = 0; i < N; i++) positions[P[i] - 1] = i;

    int maxLen = 0;
    int left = 0, right = 0;
    while (right < N) {
        while (right < N - 1 && positions[right] < positions[right + 1]) {
            right++;
        }
        maxLen = max(maxLen, right - left + 1);
        left = ++right;
    }

    cout << N - maxLen << endl;
    return 0;
}