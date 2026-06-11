#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    std::cin >> n >> a;
    int temp;
    temp = n % 500;
    if (temp <= a){
        std::cout << "Yes" << std::endl;
    }
    else{
        std::cout << "No" << std::endl;
    }
}