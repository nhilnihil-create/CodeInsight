#include <bits/stdc++.h>

int main(){
    int N, K;
    std::cin >> N >> K;
    std::vector< int > V(N);
    for(int i=0; i<N; i++){
        std::cin >> V[i];
    }
    
    int max = 0;
    for(int i=0; i<=K; i++){
        for(int j=0; j<=K-i; j++){
            int cnt = 0;
            std::priority_queue<int> que;
            if(N < i + j){
                break;
            }
            for(int l=0; l<i; l++){
                cnt += V[l];
                if(V[l] < 0){
                    que.push(-1 * V[l]);
                }
            }
            for(int r=0; r<j; r++){
                cnt += V[N - r - 1];
                if(V[N - r - 1] < 0){
                    que.push(-1 * V[N - r - 1]);
                }
            }
            for(int p=0; p<K-i-j; p++){
                if(!que.empty()){
                    cnt += que.top();
                    que.pop();
                }
            }
            //std::cout << i << " " << j << " " << cnt << std::endl;
            if(max < cnt){
                max = cnt;
            }
        }
    }
    
    std::cout << max << std::endl;
    
    return 0;
}

