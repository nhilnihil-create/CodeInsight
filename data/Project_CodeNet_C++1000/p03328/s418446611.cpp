#include<iostream>
#include<string>
#include<vector>

int main() {
    int a, b; std::cin >> a >> b;

    int diff = b - a;

    int sum = diff*(diff+1) / 2;

    std::cout << sum - b << std::endl;
}