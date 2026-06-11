#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

constexpr int INFI = 1145141919;

int main(){
	std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int N, M, X;
    std::cin >> N >> M >> X;

    std::vector<int> A;
    for(int i=0; i<M; i++){
        int buf;
        std::cin >> buf;
        A.push_back(buf);
    }

    std::vector<int> atama;
    std::vector<int> osiri;
    for(int i=0; i<M; i++){
        if(A.at(i) < X){
            atama.push_back(A.at(i));
        }else{
            osiri.push_back(A.at(i));
        }
    }

    std::cout << std::min(atama.size(), osiri.size());

    return 0;
}
