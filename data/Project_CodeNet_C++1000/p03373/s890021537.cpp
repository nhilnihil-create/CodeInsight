#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int V = max(X, Y);

    int i, j, v;
    int minv = 1000000000;
    // cout << minv << endl;
    for (int k = 0; k <= V; k++)
    {
        i = max(X - k, 0);
        j = max(Y - k, 0);
        v = A * i + B * j + C * 2 * k;
        // cout << i << " " << j << " " << 2 * k << endl;
        // cout << v << endl;
        minv = min(minv, v);
    }
    cout << minv << endl;
}