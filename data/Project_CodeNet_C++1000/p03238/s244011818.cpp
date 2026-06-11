#include<iostream>
int main(){
        int N;
        int A,B;
        std::cin >> N;
        if(N == 1) std::cout << "Hello World";
        else {
                std::cin >> A >> B;
                std::cout << A + B;
        }
}