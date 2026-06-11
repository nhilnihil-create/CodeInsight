#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    int temp = n * a;
    
    if (temp >= b){
        std::cout << b << std::endl;
    }
    else{
        std::cout << temp << std::endl;
    }
}