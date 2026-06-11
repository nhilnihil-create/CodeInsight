#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;
    std::vector< int > A(N);
    for(int i=0; i<N; i++){
        std::cin >> A[i];
    }
    
    long long ans = 0;
    std::vector< int > bit_exists(21, -1);
    int max = -1;
    for(int i=0; i<N; i++){
        for(int j=0; j<21; j++){
            
            int mask = 1 << j;
            if(A[i] & mask){
                if(max < bit_exists[j]){
                    max = bit_exists[j];
                }
                bit_exists[j] = i;
            }
        }
        ans = ans + i - max;
    }
    
    
    std::cout << ans << std::endl;
    
    return 0;
    
}
