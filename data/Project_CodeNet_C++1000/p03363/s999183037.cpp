#include <iostream>
#include <map>
using namespace std;

int main() {
    int n; cin >> n;
    long long A[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    long long S[n+1] = {};
    for (int i = 0; i < n; i++) S[i+1] = S[i] + A[i];
    map<long long, long long> nums;
    for (int i = 0; i < n + 1; i++) nums[S[i]]++;

    long long ans = 0;
    for (auto it : nums) {
        long long num = it.second;
        ans += num * (num - 1) / 2;
    }
    cout << ans << endl;
}