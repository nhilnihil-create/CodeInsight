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

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int r = 0;
    for (int k = 0; k <= 28; k++) {
        int l = 1 << k;
        int m = l * 2 - 1;

        for (int h = 0; h < 2; h++) {
            int j = 0;
            for (int i = 0; i < n; i++) {
                if (!(a[i] & l)) c[j++] = a[i];
            }
            for (int i = 0; i < n; i++) {
                if (a[i] & l) c[j++] = a[i];
            }
            if (h == 0) {
                a.swap(b);
                b.swap(c);
            } else {
                c.swap(a);
            }
        }

        int s = n;
        for (int h = 1; h <= 3; h++) {
            int t = l * h;
            int j = 0;
            for (int i = n - 1; i >= 0; i--) {
                while (j < n && (a[i] & m) + (b[j] & m) < t) j++;
                s ^= j;
            }
        }
        if (s & 1) r ^= l;
    }

    cout << r << endl;

    return 0;
}