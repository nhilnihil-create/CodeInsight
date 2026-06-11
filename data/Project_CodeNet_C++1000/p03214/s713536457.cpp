#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int best = inf, pos;
    for (int i = 0; i < n; ++i) {
        int x = abs(sum - a[i] * n);
        if (x < best) {
            best = x;
            pos = i;
        }
    }
    cout << pos << endl;
    return 0;
}
