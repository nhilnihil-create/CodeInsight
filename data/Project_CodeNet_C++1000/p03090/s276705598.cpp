#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;
const ll MOD = 998244353;

int main() {
    int N;
    cin >> N;
    if (N % 2) {
        int M = N - 1 + (N - 1) / 2 * (N - 3);
        cout << M << endl;
        for (int i = 1; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (i + j == N) continue;
                cout << i << " " << j << endl;
            }
            cout << i << " " << N << endl;
        }
    } else {
        int M = N / 2 * (N - 2);
        cout << M << endl;
        for (int i = 1; i < N; i++) {
            for (int j = i + 1; j <= N; j++) {
                if (i + j == N + 1) continue;
                cout << i << " " << j << endl;
            }
        }
    }
}