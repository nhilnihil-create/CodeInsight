#include <bits/stdc++.h>

int main(){
    int H, W, D;
    std::cin >> H >> W >> D;
    int total = H * W;
    std::vector< std::vector< int > > A_pos_H(D, std::vector< int >(total / D + (total % D != 0), 0));
    std::vector< std::vector< int > > A_pos_W(D, std::vector< int >(total / D + (total % D != 0), 0));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            int tmp;
            std::cin >> tmp;
            tmp--;
            A_pos_H[tmp % D][tmp / D] = i;
            A_pos_W[tmp % D][tmp / D] = j;
        }
    }
    std::vector< std::vector< int > > A_Csum(D, std::vector< int >(total / D + (total % D != 0), 0));
    for(int i=D; i<total; i++){
        A_Csum[i % D][i / D] = abs(A_pos_H[i % D][i / D] - A_pos_H[i % D][i / D - 1])
                             + abs(A_pos_W[i % D][i / D] - A_pos_W[i % D][i / D - 1])
                             + A_Csum[i % D][i / D - 1];
    }
    
    int Q;
    std::cin >> Q;
    std::vector< int > L(Q);
    std::vector< int > R(Q);
    for(int i=0; i<Q; i++){
        std::cin >> L[i] >> R[i];
        L[i]--;
        R[i]--;
    }
    for(int i=0; i<Q; i++){
        int ans = A_Csum[R[i] % D][R[i] / D] - A_Csum[L[i] % D][L[i] / D];
        std::cout << ans << std::endl;
    }
    
    
    
    return 0;
    
}
