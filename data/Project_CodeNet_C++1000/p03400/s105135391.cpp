#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main () {
    int n, d, x;
    std::cin >> n >> d >> x;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int ans = x;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        while((cnt)*a[i] + 1 <= d) {
            ans++;
            cnt++;
        }
    }

    std::cout << ans << "\n";
}