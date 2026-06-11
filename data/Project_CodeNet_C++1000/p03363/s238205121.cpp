#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 0;
    long long ans = 0;
    map<long long, int> nums;
    nums[sum]++;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        sum += a;
        ans += nums[sum];
        nums[sum]++;
    }
    cout << ans << endl;
}