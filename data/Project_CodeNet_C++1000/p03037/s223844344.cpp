#include <bits/stdc++.h>

int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector< int > L(M);
    std::vector< int > R(M);
    int Lmax = 0, Rmin = 1e9;
    for(int i=0; i<M; i++){
        std::cin >> L[i] >> R[i];
        
        if(Lmax < L[i]){
            Lmax = L[i];
        }
        
        if(Rmin > R[i]){
            Rmin = R[i];
        }
    }
    
    if(Lmax > Rmin){
        std::cout << 0 << std::endl;
    }else{
        std::cout << Rmin - Lmax + 1 << std::endl;
    }
    
    
    
    return 0;
    
}
