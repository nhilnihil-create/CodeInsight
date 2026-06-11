#include <iostream>
#include <vector>
int main() {
    int N;
    std::cin >> N;
    std::vector<int> Sum1(N,0),Sum2(N,0);
    std::vector<int> A2(N,0);
    std::cin >> Sum1[0];
    for(int i=1;i<N;i++){
        int A;
        std::cin >> A;
        Sum1[i] = Sum1[i-1] + A;
    }

    for(int i=0;i<N;i++){
        int A;
        std::cin >> A2[i];
    }
    Sum2[N-1] = A2[N-1];
    for(int i=N-2;i>=0;i--){
        Sum2[i] = Sum2[i+1] + A2[i];
    }

    int Max = 0;
    for(int i=0;i<N;i++){
        if(Sum1[i] + Sum2[i] > Max){
            Max = Sum1[i] + Sum2[i];
        }
    }

    std::cout << Max;
}