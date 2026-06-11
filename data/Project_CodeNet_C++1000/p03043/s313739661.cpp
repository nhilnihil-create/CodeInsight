#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

int mxN = 50000000;
vector<int> cnt(mxN + 1);

int main() {
    int n, k;
    cin >> n >> k;
    long double ans = 0;
    for (int i = 1; i <= n; i++) {
        long double x = (long double)1 / n;
        int cnt = 0;
        int m = i;
        while (m < k) {
            m *= 2;
            cnt++;
        }
        x = (long double)x * (pow((long double)1 / 2, cnt));

        ans += x;
    }
    cout << fixed << setprecision(12) << ans;

    return 0;
}