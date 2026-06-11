#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    int cost[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) cin >> cost[i][j];
    }
    vector<int> nums(10, 0);
    for (int i = 0; i < h * w; i++) {
        int x;
        cin >> x;
        if (x == -1) continue;
        nums[x]++;
    }
    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) ans += nums[i] * cost[i][1];
    cout << ans << endl;
    return 0;
}