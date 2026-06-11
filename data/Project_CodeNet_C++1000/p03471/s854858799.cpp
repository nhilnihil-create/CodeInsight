#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;

    vector<int> ijk(3);
    int res1k = -1, res5k = -1, res10k = -1;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; i + j <= N; j++) {
            int k = N - i - j; int money = 10000 * i + 5000 * j + 1000 * k;
            if (Y == money) {
                res1k = i, res5k = j, res10k = k;
            }
        }
    }

    cout << res1k << " " << res5k << " " << res10k << endl;
}