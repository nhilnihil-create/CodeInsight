#include <iostream>
//#include <vector>
#include <queue>
using namespace std;

int main() {
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};

    int h,w;
    cin >> h >> w;
    char f[55][55];
    int s=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> f[i][j];
            if(f[i][j] == '.') s++;
        }
    }
    
    queue< pair<int,int> > que;
    que.push(make_pair(0,0));
    int c[55][55] = {};
    c[0][0]=1;

    while(!que.empty() && c[h-1][w-1] == 0){
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        for(int i=0; i<4; i++){
            int q=y+dy[i];
            int p=x+dx[i];
            if(0<=q && q<h && 0<=p && p<w && f[q][p] == '.' && c[q][p] == 0){
                c[q][p] = c[y][x]+1;
                que.push(make_pair(q,p));
            }
    }
    }
    if (c[h-1][w-1] == 0){
        cout << -1 << endl;
    } else {
        cout << s - c[h-1][w-1] << endl;
    }
}