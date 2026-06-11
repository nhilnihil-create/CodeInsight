#include <bits/stdc++.h>

int main(){
    long long N, M;
    std::cin >> N >> M;
    std::vector< long long > A(N);
    for(int i=0; i<N; i++){
        std::cin >> A[i];
    }
    
    std::map< long long, int > cnt;
    
    long long total = 0;
    long long ans = 0;
    for(int i=0; i<N; i++){
        long long A_a = A[i] % M;
        total = (total + A_a) % M;
        long long total_M = (M - total) % M;
        A_a = (A_a + total_M) % M;
        auto f = cnt.find(A_a);
        if(f == cnt.end()){
            cnt[A_a] = 1;
        }else{
            cnt[A_a]++;
        }
        
        auto f2 = cnt.find(total_M);
        if(f2 != cnt.end()){
            ans += cnt[total_M];
        }
    }
    
    std::cout << ans << std::endl;
    
    
    return 0;
    
}
