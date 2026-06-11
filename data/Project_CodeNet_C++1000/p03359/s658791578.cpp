#include<iostream>
int main(){
    int a,b;
    std::cin >> a >> b;
    if(b < a) std::cout<<a-1;
    else std::cout<<a;
}