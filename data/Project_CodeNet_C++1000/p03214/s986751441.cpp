#include <algorithm>
#include <cfloat>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    double ave = (double)std::accumulate(a.begin(), a.end(), 0.0) / n;

    double min_diff = DBL_MAX;
    int min_idx = 0;
    for (int i = 0; i < n; i++) {
        double diff = ave - a[i];
        if (diff < 0) {
            diff = -diff;
        }
        if (min_diff > diff) {
            min_idx = i;
            min_diff = diff;
        }
    }
    std::cout << min_idx << std::endl;
}
