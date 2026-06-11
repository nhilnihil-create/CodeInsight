#include<iostream>
#include<vector>
#include<algorithm>

int main () {
    int cnt = 1;
    int cnt4 = 0;
    int n;
    std::cin >> n;

    bool f = n == 1 || n == 2;
    while (1)
    {

        if (n == 4)
        {
            cnt4++;
        }

        if (cnt4 == 2)
        {
            break;
        }

        if(n%2 == 0) {
            n /= 2;
        } else {
            n *= 3;
            n++;
        }

        cnt++;
    }

    if(f) {
        std::cout << 4 << "\n";
    } else {
        std::cout << cnt << "\n";
    }
}