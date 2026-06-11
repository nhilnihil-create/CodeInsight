#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

const int mod = 1e9 + 7;

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] == v[i + 1]) {
            count++;
            i++;
        }
    }

    std::cout << count << std::endl;
}
