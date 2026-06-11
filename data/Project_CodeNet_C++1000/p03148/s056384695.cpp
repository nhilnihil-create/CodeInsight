#include <bits/stdc++.h>

int main(){
    int N, K;
    std::cin >> N >> K;
    std::vector< std::pair< int, int > > DT(N);
    for(int i=0; i<N; i++){
        std::cin >> DT[i].second >> DT[i].first;
        DT[i].second--;
    }
    
    std::sort(DT.begin(), DT.end());
    
    std::vector< bool > eat_type(N, false);
    long long eat_type_num = 0;
    std::deque< int > next;
    std::deque< int > dup;
    long long score = 0;
    
    for(int i=0; i<K; i++){
        score += DT[N - i - 1].first;
        if(eat_type[DT[N - i - 1].second]){
            dup.push_back(DT[N - i - 1].first);
        }else{
            eat_type[DT[N - i - 1].second] = true;
            eat_type_num++;
        }
    }
    
    for(int i=K; i<N; i++){
        if(eat_type[DT[N - i - 1].second]){
        }else{
            next.push_back(DT[N - i - 1].first);
            eat_type[DT[N - i - 1].second] = true;
        }
    }
    
    long long score_max = score + eat_type_num * eat_type_num;
    while(!next.empty() && !dup.empty()){
        int cur_next = *next.begin();
        int cur_dup = *dup.rbegin();
        next.pop_front();
        dup.pop_back();
        
        score = score - cur_dup + cur_next;
        eat_type_num++;
        score_max = std::max(score_max, score + eat_type_num * eat_type_num);
    }
    
    
    std::cout << score_max << std::endl;
    
    return 0;
    
}
