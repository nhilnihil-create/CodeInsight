#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    cout << nums.back() << " ";
    int mn = nums[0];
    double mid = nums.back() / 2.0;
    for (int i = 1; i < n; i++) {
        if (abs(1.0 * mn - mid) > abs(1.0*nums[i]-mid)) {
            mn = nums[i];
        }
    }
    cout << mn << "\n";
    return 0;
}
