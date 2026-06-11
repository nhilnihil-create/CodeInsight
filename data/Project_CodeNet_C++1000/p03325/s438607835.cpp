#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
    int N; std::cin >> N;
    std::vector<int> a(N);
    for (auto& r : a) std::cin >> r;
    int count = 0;
    for (auto& r : a) {
        while (true) {
            if (r % 2 == 0) {
                ++count;
                r /= 2;
            }
            else
                break;
        }
    }
    std::cout << count << std::endl;

    return 0;
}