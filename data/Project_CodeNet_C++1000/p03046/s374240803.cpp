#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int M, K; cin >> M >> K;
    if (M == 0) {
        cout << (K == 0 ? "0 0" : "-1") << "\n";
        return 0;
    }
    if (M == 1) {
        cout << (K == 0 ? "0 0 1 1" : "-1") << "\n";
        return 0;
    }
    if (1<<M <= K) {
        cout << "-1\n";
        return 0;
    }
    cout << K;
    for (int i = 0; i < 1<<M; i++)
        if (i != K) cout << " " << i;
    cout << " " << K;
    for (int i = (1<<M)-1; i >= 0; i--)
        if (i != K) cout << " " << i;
}