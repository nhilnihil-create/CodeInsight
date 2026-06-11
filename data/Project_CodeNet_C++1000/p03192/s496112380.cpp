#include <iostream>

int main(){
    std::string s;
    std::cin >> s;

    int count = 0;
    for(int i = 0; i < 4; ++i){
        if('2' == s.at(i)){
            ++count;
        }
    }

    std::cout << count << std::endl;

    return 0;
}