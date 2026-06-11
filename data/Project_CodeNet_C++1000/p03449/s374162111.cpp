#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(2, vector<int>(N));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A.at(i).at(j);
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            if (j <= i) {
                sum += A.at(0).at(j);
            }
            if (j >= i) {
                sum += A.at(1).at(j);
            }
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}