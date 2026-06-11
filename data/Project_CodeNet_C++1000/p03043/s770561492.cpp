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

int main() {
    int n, k; // 100'000;
    cin >> n >> k;

    auto toss = vector<double>(n);
    for (auto t = 0; t < n; ++t) {
        auto first = t + 1;
        if (first >= k) {
            toss[t] = 0;
            continue;
        }
        auto wins = 0;
        for (auto score = first; score < k; score *= 2)
            wins++;
        toss[t] = wins;
    }

    auto sum = 0.0;
    for (auto t : toss) {
        if (t == 0) {
            sum += 1.0;
            continue;
        }
        sum += pow(0.5, double(t));
    }

    cout << setprecision(15) << (sum / n) << endl;
    return 0;
}
