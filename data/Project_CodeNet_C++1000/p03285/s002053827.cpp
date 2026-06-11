#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

#define intt long long
#define PI 3.14159265358979323846

using Graph = std::vector<std::vector<intt>>;
Graph G;

int main() {
    intt N; std::cin >> N;
    for (intt i = 0; i < 100000000; ++i) {
        intt D = N - (4 * i);
        intt j = D / 7;
        if (4 * i + 7 * j == N) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
        if (4 * i > N)
            break;
    }
    std::cout << "No" << std::endl;
    return 0;
}