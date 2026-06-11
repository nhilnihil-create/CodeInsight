#include <iostream>

int main () {
    int n;
    std::cin >> n;
    int d[n];
    for(int i = 0; i < n; ++i) {
        std::cin >> d[i];
        for(int j = 0; j < i; ++j){
            if(d[j]==d[i]){
                n -= 1;
                --i;
                break;
            }
        }
    }
    std::cout << n << std::endl;
}