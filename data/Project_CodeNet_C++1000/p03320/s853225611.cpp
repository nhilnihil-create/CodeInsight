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

int s(long long x) {
    int ans = 0;
    while (x) {
        ans += (x % 10);
        x /= 10;
    }
    return ans;
}

int main() {
    int K;
    cin >> K;
    long long x = 1e15;
    vector<long long> ans;
    while (true) {
        bool found = true;
        for (long long i = 1; found; i *= 10) {
            for (int w = 1; w <= 9; w++) {
                long long tmp = x - w * i;
                if (1.0 * tmp / s(tmp) <= 1.0 * x / s(x)) {
                    found = false;
                    x = tmp;
                    break;
                }
            }
        }
        if (x < 1) break;
        ans.push_back(x);
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < K; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
