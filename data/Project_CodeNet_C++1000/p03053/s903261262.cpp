#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

int H,W;
char f[1005][1005];
int ans;
int vx[4] = {1,0,-1,0};
int vy[4] = {0,1,0,-1};

struct corr{
    int x;
    int y;
    int d;
};

queue<corr> Q;
corr start;

int bfs()
{
    while (!(Q.empty())){
        corr now = Q.front();
        Q.pop();
        int nowx = now.x;
        int nowy = now.y;
        int nowd = now.d;
        
        for (int i = 0;i < 4;i++){
            corr next;
            next.x = nowx+vx[i];
            next.y = nowy+vy[i];
            next.d = nowd+1;
            if (0 <= next.x && next.x < H && 0 <= next.y && next.y < W && f[next.x][next.y] == '.'){
                ans = max(ans,next.d);
                f[next.x][next.y] = '#';
                Q.push(next);
            }
        }
    }
    return ans;
}


int main()
{
    cin >> H >> W;
    for (int i = 0;i < H;i++){
        for (int j = 0;j < W;j++){
            cin >> f[i][j];
            if (f[i][j] == '#'){
                start.x = i;
                start.y = j;
                start.d = 0;
                Q.push(start);
            }
        }
    }
    
    cout << bfs() << endl;
    
}
