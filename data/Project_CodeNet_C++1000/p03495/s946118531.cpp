#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[200000];

void solve() {
    int res[200001] = {0};
    for (int i = 0; i < N; ++i) {
        res[A[i]]++;
    }
    sort(res, res + 200001, greater<>());
    int num = 0;
    for (int i = K; i < 200001; ++i) {
        num += res[i];
    }
    printf("%d\n", num);
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    solve();
    return 0;
}