#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
        cin >> height[i];

    vector<int> minCost(n);
    minCost[0] = 0;
    minCost[1] = abs(height[0] - height[1]);
    for (int i = 2; i < n; i++) {
        minCost[i] = abs(height[i] - height[i - 1]) + minCost[i - 1];
        for (int j = i - 2; j >= i - k && j >= 0; j--)
            minCost[i] = min(minCost[i], abs(height[i] - height[j]) + minCost[j]);
    }

    cout << minCost.back();
    return 0;
}
