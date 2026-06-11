#include<iostream>
#include<string>
int main(){
        std::string S = "Christmas";
        int D;
        std::cin >> D;
        for(int i = 0; i < 25 - D; i++)
                S += " Eve";
        std::cout << S;
}