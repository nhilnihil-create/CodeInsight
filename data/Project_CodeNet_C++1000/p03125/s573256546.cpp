#include<iostream>
int main(){
        int A,B;
        std::cin >> A >> B;
        if(B%A == 0) std::cout<<A+B;
        else std::cout<<B-A;
}