#include<iostream>
int main(){
    int A, B, X;
    std::cin >> A >> B >> X;
    if(A <= X && A+B >= X) std::cout<<"YES";
    else std::cout<< "NO";
}