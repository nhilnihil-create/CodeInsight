#include<iostream>
#include<algorithm>
#include<vector>

int main () {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    int ans = 0;

    int num = 0;
    do {

        if(!ans) {
            num += k;
        } else {
            num += k - 1;
        }

        ans++;
    } while (num < n);

    std::cout << ans << std::endl;
}