#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, X, Y; cin >> N >> M >> X >> Y;
    bool ans = X >= Y;
    vector<int> x(N+1);
    x[0] = X;
    for (int i = 1; i <= N; i++) {
        cin >> x[i];
        ans = ans || x[i] >= Y;
    }
    for (int i = 0; i < M; i++) {
        int y; cin >> y;
        for (int j = 0; j <= N; j++) ans = ans || x[j] >= y;
    }
    cout << (ans ? "War" : "No War") << "\n";
}