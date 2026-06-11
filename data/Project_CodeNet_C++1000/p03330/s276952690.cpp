#include<bits/stdc++.h>
using ll = long long;
const ll INF_LL = 1000000000000;
#define fir first
#define sec second


int main()
{
    int n,c;
    std::cin >> n >> c;
    std::vector<std::vector<int>> dist(c,std::vector<int>(c)), map(n + 1, std::vector<int>(n + 1));
    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            std::cin >> dist[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            std::cin >> map[i][j];
            map[i][j]--;
        }
    }

    std::vector<std::map<int,int>> col_cnt(3);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            col_cnt[(i + j) % 3][map[i][j]]++;
        }
    }
    int min = 1000000000;
    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            for(int k = 0; k < c; k++){
                if(i == j || j == k || k == i)continue;
                //col_cnt[0]で色iの時
                int cur = 0;
                for(auto t : col_cnt[0]){
                    cur += dist[t.first][i] * t.second;
                }
                for(auto t : col_cnt[1]){
                    cur += dist[t.first][j] * t.second;
                }
                for(auto t : col_cnt[2]){
                    cur += dist[t.first][k] * t.second;
                }
                min = std::min(min,cur);
            }
        }
    }
    std::cout << min << std::endl;
}
