#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> a[0][i];
    }

    for (int i = 0; i < n; i++) {
        cin >> a[1][i];
    }

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n + 1; j++) {
            if (j < i) {
                sum += a[0][j];
            } else if (j == i) {
                sum += a[0][j];
            } else if (j + 1 == i) {
                sum += a[1][j - 1];
            } else if (j + 1 > i) {
                sum += a[1][j - 1];
            }
        }

        // cout << ans << ", " << sum << endl;
        ans = max(ans, sum);
    }

    cout << ans << endl;
}