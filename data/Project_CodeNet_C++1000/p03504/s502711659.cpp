#include <bits/stdc++.h>

int main(){
    int N, Cl;
    std::cin >> N >> Cl;
    std::vector< int > S(N);
    std::vector< int > T(N);
    std::vector< int > C(N);
    std::vector< std::pair< int, int > > SC(N);
    std::vector< std::pair< int, int > > TC(N);
    for(int i=0; i<N; i++){
        std::cin >> S[i] >> T[i] >> C[i];
        SC[i].first = S[i];
        SC[i].second = C[i];
        TC[i].first = T[i];
        TC[i].second = C[i];
    }
    
    std::sort(SC.begin(), SC.end());
    std::sort(TC.begin(), TC.end());
    
    int max = 0;
    std::map< int, int > mp;
    int s_index = 0;
    int t_index = 0;
    
    for(int i=1; i<=1e5; i++){
        int s_index_tmp = s_index;
        while(s_index_tmp != N && SC[s_index_tmp].first == i){
            mp[SC[s_index_tmp].second] = 1;;
            s_index_tmp++;
        }
        if(max < mp.size()){
            max = mp.size();
        }
        while(t_index != N && TC[t_index].first == i){
            auto itr = mp.find(TC[t_index].second);
            mp.erase(itr);
            t_index++;
        }
        
        while(s_index != N && SC[s_index].first == i){
            mp[SC[s_index].second] = 1;;
            s_index++;
        }
    }
    
    std::cout << max << std::endl;
    
    
    return 0;
    
}
