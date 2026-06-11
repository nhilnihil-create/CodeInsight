#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

int mxN = 50000000;
vector<int> cnt(mxN + 1);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> b(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        b[i] = make_pair(y, x);
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int j = 0;
    for (auto p : b) {
        int x = p.second, y = p.first;
        while (j < n && x--) {
            if (a[j] < y) a[j] = y;
            j++;
        }
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    cout << sum;

    return 0;
}