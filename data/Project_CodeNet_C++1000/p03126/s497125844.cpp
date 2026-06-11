#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main() {
    int N, M; std::cin >> N >> M;

    std::map<int, int> m;
    for (int i = 0; i < N; i++) {
        int K; std::cin >> K;
        for (int j = 0; j < K; j++) {
            int a; std::cin >> a;
            m[a]++;
        }
    }

    int ans = 0;
    for (auto x : m) if (x.second == N) ans++;
    std::cout << ans << std::endl;

	return 0;
}