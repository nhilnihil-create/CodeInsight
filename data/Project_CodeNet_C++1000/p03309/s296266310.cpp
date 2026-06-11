#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        x -= i + 1;
        a[i] = x;
    }
    sort(a.begin(), a.end());
    int c;
    if (n % 2 == 0) {
        c = (a[n / 2 - 1] + a[n / 2]) / 2;
    } else {
        c = a[n / 2];
    }
    c--;
    long long ans = __LONG_LONG_MAX__;
    long long tmpans;
    for (int i = 0; i < 3; i++) {
        tmpans = 0;
        for (int j = 0; j < n; j++) { tmpans += abs(a[j] - c); }
        ans = min(ans, tmpans);
        c++;
    }
    cout << ans << endl;
}