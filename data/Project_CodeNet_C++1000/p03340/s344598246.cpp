//
// Created by Mahmoud Rashad on 11/27/19.
//

#include <bits/stdc++.h>


using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<ii, ii>> vii;

bool check(vector<int> &cnt) {
    for (int &x : cnt) {
        if (x > 1)
            return true;
    }
    return false;
}

void mark(int x, vector<int> &cnt, int val) {
    int i = 0;
    while (x) {
        if (x & 1)
            cnt[i] += val;
        x /= 2;
        ++i;
    }
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;

    long long ans = 0;
    vector<int> cnt(20, 0);
    int l = 0, r = 0;
    while (l < n && r < n) {
        mark(arr[r], cnt, 1);
        while (l < r && check(cnt)) {
            mark(arr[l], cnt, -1);
            ++l;
        }
        ans += r - l + 1;
        ++r;
    }

    cout << ans << '\n';

    return 0;
}