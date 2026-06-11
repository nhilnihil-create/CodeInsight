#include<iostream>
#include<cmath>
int main(){
        int a,b,c,d;
        std::cin >> a >> b >> c >> d;
        if(std::abs(a - b) <= d && std::abs(b - c) <= d || std::abs(a-c) <= d) std::cout<<"Yes";
        else std::cout<<"No";
}