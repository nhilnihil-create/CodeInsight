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
    int mn= mxN, mx = 0;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        mx = max(x, mx);
        mn = min(y, mn);
    }
    int ans = mn - mx + 1;
    if (ans <= 0) {
        cout << 0;
    }
    else {
        cout << ans;
    }

    return 0;
}