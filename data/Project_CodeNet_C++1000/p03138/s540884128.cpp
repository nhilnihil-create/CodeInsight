#include <bits/stdc++.h>

int main(){
    int N;
    long long K;
    std::cin >> N >> K;
    std::vector< long long > A(N);
    for(int i=0; i<N; i++){
        std::cin >> A[i];
    }
    
    std::vector< int > bit_cnt(40, 0);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<40; j++){
            long long mask = (long long)1 << j;
            if(A[i] & mask){
                bit_cnt[j]++;
            }
        }
    }
    
    long long f_max_X = 0;
    for(int i=40; i>=0; i--){
        if(bit_cnt[i] * 2 < N){
            long long f_max_X_tmp = f_max_X + ((long long)1 << i);
            if(f_max_X_tmp > K){
                continue;
            }else{
                f_max_X = f_max_X_tmp;
            }
        }
    }
    
    long long ans = 0;
    for(int i=0; i<40; i++){
        long long mask = (long long)1 << i;
        if(f_max_X & mask){
            ans += (N - bit_cnt[i]) * mask;
        }else{
            ans += bit_cnt[i] * mask;
        }
    }
    
    std::cout << ans << std::endl;
    
    
    return 0;
    
}
