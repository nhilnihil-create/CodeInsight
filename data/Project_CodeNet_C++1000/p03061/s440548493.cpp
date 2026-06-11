#ifdef _MSC_VER
#include <__msvc_all_public_headers.hpp>
#undef min
#undef max
#else
#define NDEBUG
#include <bits/stdc++.h>
#endif

using namespace std;
using large = long long;

array<int, 100'005> A;
array<int, 100'005> leftgcd;
array<int, 100'005> rightgcd;

int main() {
    int n;
    cin >> n;
    for (auto i = 1; i <= n; ++i)
        cin >> A[i];

    leftgcd[0] = 0;
    leftgcd[1] = A[1];
    for (auto i = 2; i <= n; ++i) {
        leftgcd[i] = gcd(A[i], leftgcd[i - 1]);
    }
    leftgcd[n + 1] = 0;

    rightgcd[n + 1] = 0;
    rightgcd[n] = A[n];
    for (auto i = n - 1; i >= 1; --i) {
        rightgcd[i] = gcd(A[i], rightgcd[i + 1]);
    }
    rightgcd[0] = 0;

    auto max_possible = 0;
    for (auto pos = 1; pos <= n; ++pos) {
        auto left = leftgcd[pos - 1];
        auto right = rightgcd[pos + 1];

        if (left == 0)
            max_possible = max(max_possible, right);
        else if (right == 0)
            max_possible = max(max_possible, left);
        else
            max_possible = max(max_possible, gcd(left, right));
    }

    cout << max_possible << "\n";
    return 0;
}
