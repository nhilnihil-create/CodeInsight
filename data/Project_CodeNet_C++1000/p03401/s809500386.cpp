#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    a[0] = 0; a[n + 1] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int sum = 0;
    for (int j = 1; j < n + 2; ++j) sum += abs(a[j] - a[j - 1]);
    for (int i = 1; i < n + 1; ++i) cout << sum - ((abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1])) - abs(a[i + 1] - a[i - 1]))  << endl;
}
