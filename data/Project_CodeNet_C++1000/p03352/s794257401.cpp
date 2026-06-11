#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

int main () {
    int x; std::cin >> x;


    int base = std::sqrt(x);
    int ans = 1;
    for(int i = 2; i <= base; i++) {
        int j = 1;
        int max;
        while(1) {
            if(std::pow(i, j) > x) {
                max = std::pow(i, j - 1);
                break;
            }
            j++;
        }

        ans = std::max(ans, max);
    }

    std::cout << ans << std::endl;
}