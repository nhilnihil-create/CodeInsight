#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int left = a + b, right = c + d;
    if (left > right){
        std::cout << "Left" << std::endl;
    }
    else if(left == right){
        std::cout << "Balanced" << std::endl;
    }
    else{
        std::cout << "Right" << std::endl;
    }
}