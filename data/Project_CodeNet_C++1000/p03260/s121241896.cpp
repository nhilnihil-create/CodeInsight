#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
int main()
{
    long A,B;
    std::cin >> A >> B;
    if(A*B%2==1){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
    return 0;
}