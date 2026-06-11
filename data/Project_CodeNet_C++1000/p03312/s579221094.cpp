#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> S(N + 1);
    S[0] = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S[i + 1] = S[i] + A[i];
    }

    vector<pair<long long, long long>> left(N), right(N);
    int left_divider = 1, right_divider = N - 1;
    long long diff, prev_diff, p, q, r, s;
    for (int i = 2; i < N - 1; i++) {
        p = S[left_divider];
        q = S[i] - S[left_divider];
        diff = abs(q - p);
        while (1) {
            if (i - left_divider < 2) {
                break;
            }
            prev_diff = diff;
            left_divider += 1;
            p = S[left_divider];
            q = S[i] - S[left_divider];
            diff = abs(q - p);
            if (diff >= prev_diff) {
                left_divider -= 1;
                break;
            }
        }
        p = S[left_divider];
        q = S[i] - S[left_divider];
        left[i] = {p, q};
    }

    diff = 0;
    for (int i = N - 2; i > 1; i--) {
        r = S[right_divider] - S[i];
        s = S[N] - S[right_divider];
        diff = abs(s - r);
        while (1) {
            if (right_divider - i < 2) {
                break;
            }
            prev_diff = diff;
            right_divider -= 1;
            r = S[right_divider] - S[i];
            s = S[N] - S[right_divider];
            diff = abs(s - r);
            if (diff >= prev_diff) {
                right_divider += 1;
                break;
            }
        }
        r = S[right_divider] - S[i];
        s = S[N] - S[right_divider];
        right[i] = {r, s};
    }

    long long ans = 1e18;
    long long Max, Min;
    for (int i = 2; i < N - 1; i++) {
        Max = max(max(left[i].first, left[i].second),
                  max(right[i].first, right[i].second));
        Min = min(min(left[i].first, left[i].second),
                  min(right[i].first, right[i].second));
        ans = min(ans, Max - Min);
    }
    cout << ans << endl;
    return 0;
}
