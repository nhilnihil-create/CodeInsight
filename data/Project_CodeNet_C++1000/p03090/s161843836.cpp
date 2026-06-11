#include<iostream>

int main() {
    int N;
    std::cin >> N;
    if(N%2==0){
        std::cout << N*(N-2)/2 << std::endl;
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                if(i+j!=N+1){
                    std::cout << i << " " << j << std::endl;
                }
            }
        }
    }
    if(N%2==1){
        std::cout << (N-1)*(N-1)/2 << std::endl;
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                if(i+j!=N){
                    std::cout << i << " " << j << std::endl;
                }
            }
        }
    }
}