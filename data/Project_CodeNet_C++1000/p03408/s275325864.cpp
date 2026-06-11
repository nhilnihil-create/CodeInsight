#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
int main()
{
    std::map<std::string, int> hoge;
    int N, M;
    std::cin >> N;
    std::string s;
    for (int i = 0; i < N; i++) {
        std::cin >> s;
        hoge[s]++;
    }
    std::cin >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> s;
        hoge[s]--;
    }
    int ans = hoge.begin()->second;
    for (auto it = hoge.begin(); it != hoge.end(); it++) {
        ans = std::max(ans, it->second);
    }
    if (ans < 0) {
        ans = 0;
    }
    std::cout << ans << std::endl;
}
