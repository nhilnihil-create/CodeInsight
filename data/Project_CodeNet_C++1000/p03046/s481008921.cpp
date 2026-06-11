#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

int mxN = 1e6 + 1;

int main() {
    int m, k;
    cin >> m >> k;
    if (m == 0) {
        if (k == 0) {
            cout << "0 0";
            return 0;
        }
        else {
            cout << -1;
            return 0;
        }
    }
    if (m == 1) {
        if (k == 0) {
            cout << "0 0 1 1";
            return 0;
        }
        else {
            cout << -1;
            return 0;
        }
    }
    if (k >= (1 << m)) {
        cout << -1;
        return 0;
    }
    vector<int> ans;
    for (int i = 0; i < (1 << m); i++) {
        if (i == k) continue;
        ans.push_back(i);
    }
    ans.push_back(k);
    for (int i = (1 << m) - 1; i >= 0; i--) {
        if (i == k) continue;
        ans.push_back(i);
    }
    ans.push_back(k);
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}