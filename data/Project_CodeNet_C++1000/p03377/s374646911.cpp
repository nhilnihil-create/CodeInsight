#include<iostream>

int main(){
    int A, B, X;
    std::cin >> A >> B >> X;
    if(A <= X && X <= A + B){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
    return 0;
}
