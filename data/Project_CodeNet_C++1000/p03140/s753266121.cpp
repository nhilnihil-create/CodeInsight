#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

const int mod = 1e9 + 7;

int main()
{
    int n;
    std::cin >> n;

    std::string a, b, c;
    std::cin >> a >> b >> c;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && b[i] == c[i]) {
            continue;
        }

        if (a[i] != b[i] && b[i] != c[i] && c[i] != a[i]) {
            ans += 2;
        } else {
            ans++;
        }
    }
    std::cout << ans << std::endl;
}
