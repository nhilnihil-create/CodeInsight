//#define _XCODE_DEBUG

#include <iostream>
#include <queue>
#include <algorithm>

#ifdef _XCODE_DEBUG
    #include <fstream>
#endif

int main() {
    #ifdef _XCODE_DEBUG
        std::ifstream in("input.txt");
        std::cin.rdbuf(in.rdbuf());
    #endif
    
    // input data
    int H, W;
    std::cin >> H >> W;
    char maze[H][W];
    int cmap[H][W];
    std::queue<int> qi;
    std::queue<int> qj;
    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            std::cin >> maze[i][j];
            cmap[i][j] = 0;
            if (maze[i][j]=='#') {
                qi.push(i);
                qj.push(j);
            }
        }
    }
    
    // bfs
    int di[4] = {1,-1,0,0};
    int dj[4] = {0,0,1,-1};
    while (!qi.empty()) {
        int i = qi.front(); qi.pop();
        int j = qj.front(); qj.pop();
        for (int k=0; k<4; ++k) {
            int mi = i + di[k];
            int mj = j + dj[k];
            if (maze[mi][mj]=='#') continue;
            if (mi<0 || mi>=H || mj<0 || mj>=W) continue;
            maze[mi][mj] = '#';
            cmap[mi][mj] = cmap[i][j] + 1;
            qi.push(mi);
            qj.push(mj);
        }
    }
    
    int max_v = 0;
    for (int i=0; i<H; ++i) max_v=std::max(max_v, (int)*std::max_element(cmap[i],cmap[i]+W));
    std::cout << max_v << "\n";
    return 0;
}