#include<iostream>
#include<vector>
#include<string>

int main(){
    int N, M, X, Y;
    std::cin >> N >> M >> X >> Y;
    int xMax = -100, yMin = 100;
    for(int i = 0; i < N; i++){
        int x;
        std::cin >> x;
        xMax = std::max(xMax, x);
    }
    for(int i = 0; i < M; i++){
        int y;
        std::cin >> y;
        yMin = std::min(yMin, y);
    }

    for(int Z = X + 1; Z <= Y; Z++){
        if(Z > xMax && Z <= yMin){
            std::cout << "No War" << std::endl;
            return 0;
        }
    }

    std::cout << "War" << std::endl;
    return 0;
}
