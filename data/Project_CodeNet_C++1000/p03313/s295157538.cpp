#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> A((1 << N) + 1);
    for (int i = 0; i < (1 << N); ++i) {
        cin >> A[i];
    }
    A[1 << N] = -1;

    vector<int> best1(1 << N, 1 << N), best2(1 << N, 1 << N);
    vector<int> answer(1 << N, 0);
    for (int i = 0; i < (1 << N); ++i) {
        for (int j = 0; j < N; ++j)
            if ((1 << j) & i) {
                int k = i - (1 << j);
                if (A[best2[k]] > A[best1[i]]) {
                    best2[i] = best1[i];
                    best1[i] = best2[k];
                } else if (A[best2[k]] > A[best2[i]] && best2[k] != best1[i]) {
                    best2[i] = best2[k];
                }
                if (A[best1[k]] > A[best1[i]]) {
                    best2[i] = best1[i];
                    best1[i] = best1[k];
                } else if (A[best1[k]] > A[best2[i]] && best1[k] != best1[i]) {
                    best2[i] = best1[k];
                }
            }
        if (A[i] > A[best1[i]]) {
            best2[i] = best1[i];
            best1[i] = i;
        } else if (A[i] > A[best2[i]]) {
            best2[i] = i;
        }
        answer[i] = A[best1[i]] + A[best2[i]];
        for (int j = 0; j < N; ++j)
            if ((1 << j) & i) {
                int k = (i & ((1 << j) - 1));
                k = i - k - 1;
                answer[i] = max(answer[i], answer[k]);
            }
    }

    for (int i = 1; i < (1 << N); ++i)
        cout << answer[i] << "\n";
}