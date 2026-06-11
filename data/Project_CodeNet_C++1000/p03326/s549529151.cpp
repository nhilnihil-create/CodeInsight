#include <bits/stdc++.h>

int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector< long long > X(N);
    std::vector< long long > Y(N);
    std::vector< long long > Z(N);
    for(int i=0; i<N; i++){
        std::cin >> X[i] >> Y[i] >> Z[i];
    }
    
    long long ans = -1e18;
    for(int pat=0; pat<8; pat++){
        std::vector< long long > score(N, 0);
        for(int i=0; i<N; i++){
            if(pat & 4){
                score[i] += X[i];
            }else{
                score[i] -= X[i];
            }
            
            if(pat & 2){
                score[i] += Y[i];
            }else{
                score[i] -= Y[i];
            }
            
            if(pat & 1){
                score[i] += Z[i];
            }else{
                score[i] -= Z[i];
            }
        }
        std::sort(score.begin(), score.end());
        
        long long score_M = 0;
        for(int i=0; i<M; i++){
            score_M += score[N - i - 1];
        }
        if(ans < score_M){
            ans = score_M;
        }
    }
    
    std::cout << ans << std::endl;
    
    
    return 0;
    
}
