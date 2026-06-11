#include <bits/stdc++.h>

int main(){
    int N, M, Q_num;
    std::cin >> N >> M >> Q_num;
    
    std::vector< int > L(M);
    std::vector< int > R(M);
    std::vector< std::vector< int > > LR_cnt(N, std::vector< int >(N, 0));
    std::vector< int > P(Q_num);
    std::vector< int > Q(Q_num);
    for(int i=0; i<M; i++){
        std::cin >> L[i] >> R[i];
        LR_cnt[L[i]-1][R[i]-1]++;
    }
    for(int i=0; i<Q_num; i++){
        std::cin >> P[i] >> Q[i];
    }
    
    std::vector< std::vector< int > > LR_cnt_acc_v(N, std::vector< int >(N, 0));
    for(int i=0; i<N; i++){
        LR_cnt_acc_v[0][i] = LR_cnt[0][i];
        for(int j=1; j<N; j++){
            LR_cnt_acc_v[j][i] = LR_cnt_acc_v[j-1][i] + LR_cnt[j][i];
        }
    }
    std::vector< std::vector< int > > LR_cnt_acc(N, std::vector< int >(N, 0));
    for(int i=0; i<N; i++){
        LR_cnt_acc[i][0] = LR_cnt_acc_v[i][0];
        for(int j=1; j<N; j++){
            LR_cnt_acc[i][j] = LR_cnt_acc[i][j-1] + LR_cnt_acc_v[i][j];
        }
    }
    
    for(int i=0; i<Q_num; i++){
        if(P[i] == 1){
            std::cout << LR_cnt_acc[Q[i]-1][Q[i]-1] << std::endl;
        }else{
            std::cout << LR_cnt_acc[Q[i]-1][Q[i]-1] - LR_cnt_acc[P[i]-2][Q[i]-1] << std::endl;
        }
    }
    
    
    return 0;
    
}
