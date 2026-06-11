#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L
const int mxN = 1e9 + 7;

long long check(vector<int> a, int k) {
    sort(a.begin(), a.end());
    long long sum = 0;
    int i = 0;
    int n = a.size();
    while (i < n && a[i] < 0 && k > 0) {
        k--; i++;
    }
    for (i; i < n; i++) sum += a[i];
    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> money(n);
    for (int i = 0; i < n; i++) cin >> money[i];
    long long ans = 0;

    for (int t = 0; t < min(k, n); t++) {
        vector<int> a;
        for (int i = 0; i < t; i++) {
            a.push_back(money[i]);
            ans = max(ans, check(a, k-t));
        }
        for (int j = n - 1; j >= n - (min(k, n)-t); j--) {
            a.push_back(money[j]);
            ans = max(ans , check(a, k-t- (n-j)));
        }

    }
    reverse(money.begin(), money.end());
    for (int t = 0; t < min(k, n); t++) {
        vector<int> a;
        for (int i = 0; i < t; i++) {
            a.push_back(money[i]);
            ans = max(ans, check(a, k - t));
        }
        for (int j = n - 1; j >= n - (min(k, n) - t); j--) {
            a.push_back(money[j]);
            ans = max(ans, check(a, k - t - (n - j)));
        }

    }
    cout << ans;

    return 0;
}