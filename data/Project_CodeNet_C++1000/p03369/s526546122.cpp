#include<iostream>
#include<string>
int main(){
    std::string S;
    std::cin >> S;
    int cost = 700;
    for(auto a: S)
        if(a == 'o') cost += 100;
    std::cout << cost;
}