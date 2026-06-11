#include<iostream>
#include<string>
int main(){
        std::string S;
        std::cin >> S;
        int n = 0;
        for(auto a: S){
                if(a == '+') n++;
                else n--;
        }
        std::cout<<n;
}