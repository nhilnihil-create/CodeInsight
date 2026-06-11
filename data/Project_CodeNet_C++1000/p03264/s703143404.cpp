#include<iostream>
int main(){
        int K;
        std::cin >> K;
        if(K%2 == 0) std::cout << (K/2)*(K/2);
        else std::cout<<(K/2)*(K/2)+(K/2);
}