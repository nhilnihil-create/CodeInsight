#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    int N;
    std::string S;

    std::cin >> N;
    std::cin >> S;

    int west_side = 0;
    int east_side = 0;
    for(int i = 1; i < N; i++){
        if(S.at(i) == 'E') east_side++;
    }
    int min = west_side + east_side;
    for(int i = 1; i < N; i++){
        if(S.at(i-1) == 'W') west_side++;
        if(S.at(i) == 'E') east_side--;
        min = std::min(min, west_side+east_side);
    }
    std::cout << min << std::endl;    
}
