#include <bits/stdc++.h>
using namespace std;

int main() {
    int D, N; cin >> D >> N;
    if (N == 100) {
        int ans = 1;
        for (int i = 0; i < D; i++) ans *= 100;
        cout << ans * 101 << endl;
    }
    else cout << pow(100, D) * N << endl;
}