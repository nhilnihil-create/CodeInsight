#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    long minimum = A * X + B * Y;
    for (int i = 0; i < 10e5; i++) {
        long total = A * max(0, X - i) + B * max(0, Y - i) + (long)C * i * 2;
        minimum = min(minimum, total);
    }
    cout << minimum << endl;
}
