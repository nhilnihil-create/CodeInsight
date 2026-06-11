#include <bits/stdc++.h>
#define show(x) std::cerr << #x << " = " << x << std::endl
using ll = long long;
using ld = long double;
constexpr ll MOD = 1000000007LL;
template <typename T>
constexpr T INF = std::numeric_limits<T>::max() / 10;
std::mt19937 mt{std::random_device{}()};
int main()
{
    int N;
    std::cin >> N;
    int n = 1;
    for (int sum = 0; sum < N; n++) {
        sum += n;
        if (sum > N) { return std::cout << "No" << std::endl, 0; }
    }
    n--;
    std::cout << "Yes\n"
              << n + 1 << std::endl;
    std::vector<std::vector<int>> ans(n + 1);
    int s = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++, s++) {
            ans[i].push_back(s);
            ans[i + j + 1].push_back(s);
        }
    }
    for (int i = 0; i <= n; i++) {
        std::cout << n;
        for (const int e : ans[i]) { std::cout << " " << e; }
        std::cout << std::endl;
    }
    return 0;
}
