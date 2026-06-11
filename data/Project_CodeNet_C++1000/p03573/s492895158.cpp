#include <iostream>

int main() {
    int a ,b,c ;
    std::cin>>a;
    std::cin>>b;
    std::cin>>c;
    if (a == b){
        std::cout<<c<< "\n";
    }
    else if (a==c ){
        std::cout<<b<<"\n";
    }
    else if (b==c){
        std::cout<<a;
    }
    else {
        std::cout<<"invaild error";
    }
     }