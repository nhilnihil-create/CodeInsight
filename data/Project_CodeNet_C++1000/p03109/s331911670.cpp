#include<iostream>
int main(){
        char t;
        int y,m,d;
        std::cin >> y >> t >> m >> t >> d;
        if(y <= 2019 && m <= 4) std::cout<<"Heisei";
        else std::cout<<"TBD";
}