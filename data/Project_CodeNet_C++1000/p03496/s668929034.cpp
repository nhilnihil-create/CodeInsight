#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;
    std::vector< int > A(N);
    int absmax = 0;
    int absmax_index = -1;
    for(int i=0; i<N; i++){
        std::cin >> A[i];
        int abs = std::abs(A[i]);
        if(absmax < abs){
            absmax = abs;
            absmax_index = i;
        }
    }
    
    if(absmax_index == -1){
        std::cout << 0 << std::endl;
        return 0;
    }else{
        std::cout << 2*N << std::endl;
    }
    
    if(A[absmax_index] > 0){
        std::cout << absmax_index+1 << " " << N << std::endl;
        std::cout << absmax_index+1 << " " << N << std::endl;
        for(int i=0; i<N-1; i++){
            std::cout << N << " " << i+1 << std::endl;
            std::cout << N << " " << N << std::endl;
        }
    }else{
        std::cout << absmax_index+1 << " " << 1 << std::endl;
        std::cout << absmax_index+1 << " " << 1 << std::endl;
        for(int i=N-1; i>=1; i--){
            std::cout << 1 << " " << i+1 << std::endl;
            std::cout << 1 << " " << 1 << std::endl;
        }
    }
    
    //if(A[absmax_index] > 0){
    //    A[N-1] += 2 * A[absmax_index];
    //    for(int i=1; i<N; i++){
    //        A[i] += A[N-1];
    //        A[N-1] += A[N-1];
    //    }
    //}else{
    //    A[0] += 2 * A[absmax_index];
    //    for(int i=N-2; i>=0; i--){
    //        A[i] += A[0];
    //        A[0] += A[0];
    //    }
    //}
    //
    //for(int i=0; i<N; i++){
    //    std::cout << A[i] << std::endl;
    //}
    
    
    return 0;
    
}
