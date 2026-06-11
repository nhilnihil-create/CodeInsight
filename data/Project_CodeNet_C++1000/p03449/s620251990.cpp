#include <bits/stdc++.h>

int main()
{
    int n;
    int ans = 0;
    std::cin >> n;
    std::unique_ptr<int[]> a{new int[n]};
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::unique_ptr<int[]> b{new int[n]};
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        int temp = 0;
        for (int j = 0; j <= i; ++j) {
            temp += a[j];
        }
        for (int k = i; k < n; ++k) {
            temp += b[k];
        }
        ans = std::max(temp, ans);
    }
    std::cout << ans << std::endl;
}