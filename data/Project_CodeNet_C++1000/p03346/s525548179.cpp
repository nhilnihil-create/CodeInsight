#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        Q[P[i] - 1] = i;
    }

    int left = 0, right = 0, maxLen = 0;
    while (right < N) {
        while (right < N - 1 && Q[right] < Q[right + 1]) {
            right++;
        }
        maxLen = max(maxLen, right - left + 1);
        left = ++right;
    }

    cout << N - maxLen << endl;
    return 0;
}