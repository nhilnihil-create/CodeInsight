#include<iostream>
#include<algorithm>
#include<vector>

int main() {
    std::vector<int> a(3);
    int d;
    std::cin >> a[0] >> a[1] >> a[2] >> d;

    auto max = std::max_element(a.begin(), a.end());

    int ans = 0;
    for (auto it = a.begin(); it != a.end(); it++)
    {
        if(it == max) {
            for (int i = 1; i <= d; i++) {
                *it *= 2;
            }
            ans += *it;
        }
        else
        {
            ans += *it;
        }
    }

    std::cout << ans << "\n";
}
