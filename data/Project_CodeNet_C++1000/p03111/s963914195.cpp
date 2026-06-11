#include <bits/stdc++.h>

int main(){
    int N, A, B, C;
    std::cin >> N >> A >> B >> C;
    std::vector< int > L(N);
    for(int i=0; i<N; i++){
        std::cin >> L[i];
    }
    
    int min = 1e9;
    for(int i=0; i<(int)std::pow(2, N*2); i++){
        std::vector< int > length(4, 0);
        std::vector< int > cnt(4, 0);
        for(int j=0; j<N; j++){
            int mask = 3 << (j*2);
            int index = (i & mask) >> (j*2);
            length[index] += L[j];
            cnt[index]++;
        }
        if(cnt[0] && cnt[1] && cnt[2]){
            std::sort(length.begin(), length.end()-1);
            int useMP =   std::abs(length[2] - A)
                        + std::abs(length[1] - B)
                        + std::abs(length[0] - C)
                        + 10 * (cnt[0] + cnt[1] + cnt[2] - 3);
            if(min > useMP){
                min = useMP;
            }
        }
    }
    
    std::cout << min << std::endl;;
    
    return 0;
    
}
