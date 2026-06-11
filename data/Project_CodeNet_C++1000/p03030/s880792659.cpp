#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int main(void){
    int N;
    std::vector<std::tuple<std::string, int, int>> book;
    std::cin >> N;

    for (int i=0; i<N; ++i){
        std::string s;
        int a;
        std::cin >> s >> a;
        book.emplace_back(s, a, i + 1);
    }

    std::sort(book.begin(), book.end(), [](const auto &x, const auto &y){
        return std::get<0>(x) == std::get<0>(y) ? std::get<1>(x) > std::get<1>(y) : std::get<0>(x) < std::get<0>(y);
    });

    for (auto x: book){
        std::cout << std::get<2>(x) << std::endl;
    }

    return 0;
}
