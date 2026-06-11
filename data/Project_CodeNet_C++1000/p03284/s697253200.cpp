#include<iostream>
int main(){
        int N,K;
        std::cin >> N >> K;
        std::cout<<((N%K) == 0 ? 0 : 1);
}