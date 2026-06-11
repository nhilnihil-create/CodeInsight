#include<iostream>
int main(){
        int A,B;
        std::cin >> A >> B;
        if(A<=5)std::cout<<0;
        else if(A<=12)std::cout << B/2;
        else std::cout << B;
}