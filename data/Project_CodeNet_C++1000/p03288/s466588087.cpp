#include<iostream>
int main(){
        int R;
        std::cin >> R;
        if(R < 1200) std::cout<<"ABC";
        else if(R < 2800) std::cout<<"ARC";
        else std::cout<<"AGC";
}