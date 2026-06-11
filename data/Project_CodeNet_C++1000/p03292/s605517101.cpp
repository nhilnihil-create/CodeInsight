#include<iostream>
#include<cmath>

int main(){
    int A[3];
    for(int i = 0; i < 3; i++){
        std::cin >> A[i];
    }
    int minVal = 1000;
    minVal = std::min(minVal, std::abs(A[1] - A[0]) + std::abs(A[2] - A[1]));
    minVal = std::min(minVal, std::abs(A[2] - A[1]) + std::abs(A[0] - A[2]));
    minVal = std::min(minVal, std::abs(A[0] - A[1]) + std::abs(A[2] - A[0]));
    std::cout << minVal << std::endl;
    return 0;
}
