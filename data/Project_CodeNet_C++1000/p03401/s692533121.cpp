#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) a.begin(), a.end()
#define print(x) cout << x << "\n";

int main()
{
    int n;
    cin >> n;

    vector<int> a(n + 2);
    a[0] = 0;
    a[n + 1] = 0;
    int sum = 0;

    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n + 2; i++) {
        sum += abs(a[i - 1] - a[i]);
    }
        for (int i = 1; i < n + 1; i++)
        {
            int ans = sum;
            ans += -(abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1])) + abs(a[i - 1] - a[i + 1]);
            print(ans);
        }
}