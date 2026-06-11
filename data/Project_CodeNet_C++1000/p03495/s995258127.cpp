#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int hist[N] = {0};
    int A;
    for (int i = 0; i < N; i++) {
        cin >> A;
        hist[A - 1]++;
    }
    sort(hist, hist + N);
    int l = 0;
    for (int i = 0; i < K; i++) {
        l += hist[N - 1 - i];
    }
    cout << N - l << endl;
}