#include <bits/stdc++.h>

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, c;
    std::cin >> n >> m >> c;

    std::vector<int> b(m);
    for (int &i : b) std::cin >> i;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int sum = c;
        for (int j = 0; j < m; j++) {
            sum += a[i][j] * b[j];
        }

        ans += (sum > 0);
    }

    std::cout << ans;

    return 0;
}