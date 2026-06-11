#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;
    std::vector< std::vector< int > > AB(N);
    std::map< long long, long long > dist;
    for(int i=0; i<N-1; i++){
        int tmp1, tmp2;
        long long tmp3;
        std::cin >> tmp1 >> tmp2 >> tmp3;
        AB[tmp1 - 1].push_back(tmp2 - 1);
        AB[tmp2 - 1].push_back(tmp1 - 1);
        dist[((long long)tmp1 - 1) * 1e6 + (long long)tmp2 - 1] = tmp3;
        dist[((long long)tmp2 - 1) * 1e6 + (long long)tmp1 - 1] = tmp3;
    }
    
    std::vector< int > ans(N);
    
    std::deque< int > deq_No;
    std::deque< int > deq_preNo;
    std::deque< long long > deq_dist;
    deq_No.push_back(0);
    deq_preNo.push_back(-1);
    deq_dist.push_back(0);
    
    while(!deq_No.empty()){
        int cur_No = deq_No[0];
        int cur_preNo = deq_preNo[0];
        long long cur_dist = deq_dist[0];
        deq_No.pop_front();
        deq_preNo.pop_front();
        deq_dist.pop_front();
        //std::cout << cur_No << " " << cur_preNo << " " << cur_dist << std::endl;
        
        ans[cur_No] = cur_dist % 2;
        
        for(int i=0; i<AB[cur_No].size(); i++){
            int next_No = AB[cur_No][i];
            if(next_No == cur_preNo){
                continue;
            }
            deq_No.push_back(next_No);
            deq_preNo.push_back(cur_No);
            deq_dist.push_back(cur_dist + dist[(long long)cur_No * 1e6 + (long long)next_No]);
        }
    }
    
    for(int i=0; i<N; i++){
        std::cout << ans[i] << std::endl;
    }
    
    return 0;
}

