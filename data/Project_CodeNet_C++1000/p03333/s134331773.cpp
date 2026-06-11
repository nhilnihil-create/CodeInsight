#include <bits/stdc++.h>
using namespace std;

template<typename T, int lower, int upper>
struct offset_array {
    T data[upper-lower+1];
    T& operator[](const int i) {
        return data[i-lower];
    }
};

const int MAX_RANGE = 1e5;
offset_array<int, -MAX_RANGE, MAX_RANGE> lcounts;
offset_array<int, -MAX_RANGE, MAX_RANGE> rcounts;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        lcounts[l]++;
        rcounts[r]++;
    }

    lcounts[0]++;
    rcounts[0]++;
    N++;

    long long result = 0;
    int left = 0, right = N;
    for (int x = -MAX_RANGE; x < MAX_RANGE; x++) {
        right -= lcounts[x];
        left += rcounts[x];
        result += 2 * min(left, right);
    }
    cout << result << endl;
}
