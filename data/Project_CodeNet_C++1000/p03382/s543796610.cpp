#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200100;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int best = a[0];
    for (int i = 1; i < n; ++i) {
        if (min(a[i], a[n - 1] - a[i]) > min(best, a[n - 1] - best)) {
            best = a[i];
        }
    }
    cout << a[n - 1] << ' ' << best;
    return 0;
}