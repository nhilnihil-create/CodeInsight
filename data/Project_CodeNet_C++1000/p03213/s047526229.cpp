#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;
    
    std::vector< int > cnt(N+1, 0);
    for(int i=2; i<=N; i++){
        int cur = i;
        for(int j=2; j*j<=N; j++){
            while(cur % j == 0){
                cur /= j;
                cnt[j]++;
            }
            if(cur == 1){
                break;
            }
        }
        cnt[cur]++;
    }
    cnt[1] = 1;
    
    int ans = 0;
    
    std::deque< int > num;
    std::deque< int > next;
    num.push_back(1);
    next.push_back(2);
    
    while(!num.empty()){
        int cur_num = num[0];
        int cur_next = next[0];
        num.pop_front();
        next.pop_front();
        if(cur_num == 75){
            ans++;
        }
        if(cur_num >= 75){
            continue;
        }
        if(cur_next > N){
            continue;
        }
        
        for(int i=0; i<=cnt[cur_next]; i++){
            int tmp = cur_num * (i+1);
            if(tmp > 75){
                break;
            }
            num.push_back(cur_num * (i+1));
            next.push_back(cur_next+1);
        }
    }
    
    std::cout << ans << std::endl;;
    
    return 0;
    
}
