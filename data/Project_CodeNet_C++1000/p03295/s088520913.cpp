//#define _XCODE_DEBUG

#include <iostream>
#include <vector>

#ifdef _XCODE_DEBUG
    #include <fstream>
#endif

int main() {
    #ifdef _XCODE_DEBUG
        std::ifstream in("input.txt");
        std::cin.rdbuf(in.rdbuf());
    #endif
    int N, M;
    std::cin >> N >> M;
    int m1, m2;
    std::vector<std::pair<int, int>> pair_vec;
    for (int i=0; i<M; ++i) {
        std::cin >> m1 >> m2;
        pair_vec.push_back(std::make_pair(m1-1, m2-1));
    }
    std::sort(pair_vec.begin(), pair_vec.end(), [](auto &l, auto &r) {
        return r.second > l.second;
    });
    
    // remove bridges
    int ans = 1, ind = pair_vec[0].second-1;
    for (int i=1; i<M; ++i) {
        if (pair_vec[i].first > ind){
            ind = pair_vec[i].second - 1;
            ++ans;
        }
    }
    std::cout << ans << "\n";
    return 0;
}