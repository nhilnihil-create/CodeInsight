#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X, total = 0;
    cin >> N >> X;

    int m[N];
    for (int i = 0; i < N; i++) {
        cin >> m[i];
        X -= m[i];
        total++;
    }

    sort(m, m + N, greater<int>());

    total += X / m[N -1];

    cout << total << endl;
}