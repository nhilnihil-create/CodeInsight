#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
    int n;  cin >> n;
    int *a = new int[n+2];
    a[0] = 0, a[n+1] = 0;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n+1; i++)
        ans += abs(a[i+1]-a[i]);

    for (int i = 1; i <= n; i++) {
        cout << ans - abs(a[i]-a[i-1]) - abs(a[i+1]-a[i]) + abs(a[i+1]-a[i-1]) << endl;
    }

    return 0;
}