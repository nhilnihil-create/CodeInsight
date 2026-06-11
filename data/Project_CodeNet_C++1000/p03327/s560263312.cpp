#include<iostream>
#include<string>

int main(){
    std::string S;
    std::cin >> S;
    if(S.size() <= 3){
        std::cout << "ABC" << std::endl;
    }else{
        std::cout << "ABD" << std::endl;
    }
    return 0;
}
