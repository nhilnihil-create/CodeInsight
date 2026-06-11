#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int r = 0;
    for (int k = 28; k >= 0; k--) {
        int l = 1 << k;
        sort(b.begin(), b.end());

        int s = 0;
        for (int h = 0; h < 3; h++) {
            int t = l * (h + 1);
            for (int i = 0; i < n; i++) {
                s ^= b.end() - lower_bound(b.begin(), b.end(), t - a[i]);
            }
        }
        if (s & 1) r ^= l;

        for (int i = 0; i < n; i++) {
            a[i] &= ~l;
            b[i] &= ~l;
        }
    }

    cout << r << endl;

    return 0;
}