#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    rep(i, N) {
        cin >> X[i];
        Y[i] = X[i];
    }
    sort(Y.begin(), Y.end());
    rep(i, N) {
        if (X[i] < Y[N / 2]) {
            cout << Y[N / 2] << "\n";
        } else {
            cout << Y[N / 2 - 1] << "\n";
        }
    }
}