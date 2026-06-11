#include "bits/stdc++.h"

using namespace std;

int main() {
    vector<int> X(3);
    cin >> X[0] >> X[1] >> X[2];

    sort(X.begin(), X.end());
    int A = X[2] - X[0];
    int B = X[2] - X[1];

    int ans = A / 2 + B / 2;
    A = A % 2;
    B = B % 2;

    if (A + B == 0)
        cout << ans << endl;
    else if (A + B == 2)
        cout << ans + 1 << endl;
    else
        cout << ans + 2 << endl;
}