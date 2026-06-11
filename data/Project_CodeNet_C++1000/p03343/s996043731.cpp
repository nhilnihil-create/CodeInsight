#ifndef LOCAL
#include <bits/stdc++.h>
#else
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <random>
#include <chrono>
#include <fstream>
#include <deque>
#include <numeric>
#include <functional>
#endif
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int ans = numeric_limits<int>::max();
    for (int low : a) {
        vector<int> have;
        vector<int> moves;

        for (int i = 0; i < n; ++i) {
            if (a[i] < low)
                have.clear();
            else {
                have.push_back(a[i]);

                if (i + 1 == n || a[i + 1] < low) {
                    sort(have.begin(), have.end());
                    for (int j = 0; j + k <= int(have.size()); ++j)
                        moves.push_back(have[j]);
                }
            }
        }

        if (int(moves.size()) < q)
            continue;

        sort(moves.begin(), moves.end());
        ans = min(ans, moves[q - 1] - low);
    }

    cout << ans;
    return 0;
}
