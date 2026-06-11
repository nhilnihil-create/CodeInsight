#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> A(N + 1, 777);
    int small = 0, large = 0;
    for (int i = 0; i < M; i++) {
        int y;
        cin >> y;
        A.at(y) = y;
        if (A.at(y) <= X) {
            small++;
        }
        else if (X <= A.at(i)) {
            large++;
        }
    }

    int ans = 0;
    if (large < small) {
        for (int i = X; i <= N; i++) {
            if (i == A.at(i)) ans++;
            if (X == N) break;
        }
    }
    else {
        for (int i = X; 0 <= i; i--) {
            if (i == A.at(i)) ans++;
            if (i == 0) break;
        }
    }
    cout << ans << endl;
}