#include<iostream>
#include<vector>

int main(){
    int a, b;
    std::cin >> a >> b;
    int diff = b - a;
    int snow = -a;
    for(int i = 1; i < diff; i++){
        snow += i;
    }
    std::cout << snow << std::endl;
    return 0;
}
