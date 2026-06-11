#include <bits/stdc++.h>

int main(){
    int N, C;
    std::cin >> N >> C;
    std::vector< std::vector< int > > D(C, std::vector< int >(C));
    std::vector< std::vector< int > > color(N, std::vector< int >(N));
    for(int i=0; i<C; i++){
        for(int j=0; j<C; j++){
            std::cin >> D[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            std::cin >> color[i][j];
            color[i][j]--;
        }
    }
    
    std::vector< std::vector< int > > color_cost(C, std::vector< int >(3, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<C; k++){
                color_cost[k][(i+j)%3] += D[color[i][j]][k];
            }
        }
    }
    
    int min = 1e9;
    for(int i=0; i<C; i++){
        for(int j=0; j<C; j++){
            if(i == j){
                continue;
            }
            for(int k=0; k<C; k++){
                if(i == k || j == k){
                    continue;
                }
                int cur = color_cost[i][0] + color_cost[j][1] + color_cost[k][2];
                if(min > cur){
                    min = cur;
                }
            }
        }
    }
    
    std::cout << min << std::endl;
    
    
    return 0;
    
}
