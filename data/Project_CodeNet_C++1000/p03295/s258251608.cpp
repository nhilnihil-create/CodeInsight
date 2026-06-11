#include <bits/stdc++.h>

int main(){
    long long N, M;
    std::cin >> N >> M;
    std::vector< std::pair< int, int > > BA(M);
    for(int i=0; i<M; i++){
        std::pair< int, int > tmp;
        std::cin >> tmp.second >> tmp.first;
        BA[i] = tmp;
    }
    
    std::sort(BA.begin(), BA.end());
    
    int brid = -1;
    int ans = 0;
    for(int i=0; i<M; i++){
        if(BA[i].second >= brid){
            brid = BA[i].first;
            ans++;
        }
    }
    
    std::cout << ans << std::endl;
    
    
    return 0;
    
}
