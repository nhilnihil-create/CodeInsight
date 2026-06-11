#include <algorithm>
#include <iostream>

int main(){
    std::string s;
    std::cin >> s;

    if(3 == s.size()){
        std::reverse(std::begin(s), std::end(s));
    }

    std::cout << s << std::endl;

    return 0;
}