#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, A, B, C;
    cin >> A >> B >> C >> X;

    int cnt = 0;
    int sum = 0;
    for (int i = 0; i <= A; i++) {
        sum = 500 * i;
        if (sum > X) {
            break;
        }
        for (int j = 0; j <= B; j++) {
            sum = (500 * i + 100 * j);
            if (sum > X) {
                break;
            }

            if ((X - sum) / 50 <= C) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}