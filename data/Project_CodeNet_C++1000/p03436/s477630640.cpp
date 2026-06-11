//
// Created by TakahiroYamaji on 2020/08/14.
//
#include<iostream>
#include<queue>
char field[51][51];
int visited[51][51];
int dis[51][51];
int H, W;
typedef std::pair<int, int> P;
std::queue<P> Q;
int dh[] = {-1, 0, 1, 0};
int dw[] = {0, 1, 0, -1};

void init_dis(int h,int  w){
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            dis[i][j] = 1000000;
        }
    }
}

//void init_que(){
//    Q.push(P(0, 0));
//    dis[0][0] = 1;
//}

void bfs(){
    Q.push(P(0, 0));
    dis[0][0] = 0;

    while(!Q.empty()){
        P p = Q.front();
        Q.pop();
        visited[p.first][p.second] = 1;
        for (int i=0;i<4;i++){
            int next_h = p.first + dh[i];
            int next_w = p.second + dw[i];
            if (0 <= next_h && next_h < H && 0 <= next_w && next_w < W && dis[next_h][next_w] == 1000000){
                if (field[next_h][next_w] == '.'){
                    Q.push(P(next_h, next_w));
                    if (dis[next_h][next_w] > dis[p.first][p.second] + 1){
                        dis[next_h][next_w]  = dis[p.first][p.second] + 1;
                    }
                }

            }
        }
    }
}

void print_dis(){
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            std::cout << dis[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    std::cin >> H >> W;
    int cnt = 0;
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            std::cin >> field[i][j];
            if (field[i][j] == '#')cnt++;
        }
    }

    init_dis(H, W);
    //init_que();
    bfs();

    int res = dis[H-1][W-1];
    int ans = H * W - res - cnt - 1;
    if (res == 1000000){
        std::cout << -1 << std::endl;
    }else{
        std::cout << ans << std::endl;
    }
//    std::cout << ans << std::endl;
//    std::cout << res << std::endl;
//    //print_dis();
}

