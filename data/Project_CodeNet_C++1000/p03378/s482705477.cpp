#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main () {
    int n, m, x;
    std::cin >> n >> m >> x;
    std::vector<int> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }

    int ansa = 0;
    int ansb = 0;

    for (int i = 0; i < m; i++) {
        if(a[i] > 0 && a[i] < x) {
            ansa++;
        }

        if(a[i] > x && a[i] < n) {
            ansb++;
        }
    }

    std::cout << std::min(ansa, ansb) << "\n";
}