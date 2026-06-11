#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<vector<char>> S(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        string t; cin >> t;
        for (int j = 0; j < N; j++) {
            S[i][j] = t[j];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        bool f = true;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (S[j][(k+N-i)%N] != S[k][(j+N-i)%N]) {
                    f = false;
                    break;
                }
            }
        }
        if (f) ans += N;
    }
    cout << ans << endl;
}
