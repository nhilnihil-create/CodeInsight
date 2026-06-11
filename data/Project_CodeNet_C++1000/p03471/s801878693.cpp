#include <iostream>

void exchange(int a, int *n_1000, int *n_5000, int *n_10000){
    if (a == 1000) // 5*1000 to 5000
    {
        *n_1000 -= 5;
        *n_5000 += 1;
    }
    else if (a == 5000) // 2*5000 to 10000
    {
        *n_5000 -= 2;
        *n_10000 += 1;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

int main(){
    int n, y;
    std::cin >> n >> y;
    int n_1000 = y / 1000;
    int n_5000 = 0;
    int n_10000 = 0;

    if (n == n_1000)
    {
        std::cout << n_10000 << " " << n_5000 << " " << n_1000 <<std::endl;
        return 0;
    }
    
    while (n_1000 >= 5)
    {
        exchange(1000, &n_1000, &n_5000, &n_10000);
        if (n_1000 + n_5000 + n_10000 == n)
        {
            std::cout << n_10000 << " " << n_5000 << " " << n_1000 <<std::endl;
            return 0;
        }
        int count = 0;
        while (n_5000 >= 2)
        {
            exchange(5000, &n_1000, &n_5000, &n_10000);
            count++;
            if (n_1000 + n_5000 + n_10000 == n)
            {
                std::cout << n_10000 << " " << n_5000 << " " << n_1000 <<std::endl;
                return 0;
            }
        }
        n_5000 += 2 * count;
        n_10000 -= count;
    }
    std::cout << "-1 -1 -1" << std::endl;
    return 0;
}