#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(2, std::vector<int>(n));
    for(int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }

    int max = -1;
    int sum;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int k = 0; k <= i; k++) {
            sum += a[0][k];
        }

        for (int j = i; j < n; j++) {
            sum += a[1][j];
        }

        max = std::max(sum, max);
    }

    std::cout << max << "\n";
}