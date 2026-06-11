#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    if (k == 1) {
        ans = n * n * n;
    } else if (k % 2 == 1) {
        ans = (n / k) * (n / k) * (n / k);
    } else {
        ans += (n / k) * (n / k) * (n / k);
        if (n >= k / 2) {
            ans += ((n - (k / 2)) / k + 1) * ((n - (k / 2)) / k + 1) *
                   ((n - (k / 2)) / k + 1);
        }
    }
    cout << ans << endl;
}