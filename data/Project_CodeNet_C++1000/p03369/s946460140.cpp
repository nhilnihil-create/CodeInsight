#include <iostream>

int main(int argc, char **argv){

    const int BASE_COST = 700;
    const int OPTION_COST = 100;

    std::string S;
    std::cin >> S;

    int count = 0;
    for(int i = 0; i < S.size(); i++){
        if(S.at(i) == 'o') count++;
    }
    std::cout << (count * OPTION_COST + BASE_COST) << std::endl;
}
