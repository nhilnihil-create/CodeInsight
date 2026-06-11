#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int H,W;
    cin >> H >> W;

    vector<string> s(H);
    for(int i=0;i<H;i++) cin >> s[i];

    int shapenum = 0;
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) if(s[i][j]=='#') shapenum++;


    queue<pair<int,int>> q;
    vector<vector<int>> dist(50,vector<int>(50,-1));
    q.push(make_pair(0,0));
    dist[0][0] = 1;

    const int dh[4] = {0,1,0,-1};
    const int dw[4] = {1,0,-1,0};

    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();

        int h = p.first, w = p.second;
        for(int i=0;i<4;i++){
            int nh = h+dh[i];
            int nw = w+dw[i];

            if(nh<0||nh>=H||nw<0||nw>=W) continue;
            if(dist[nh][nw]!=-1) continue;
            if(s[nh][nw]=='#') continue;

            q.push(make_pair(nh,nw));
            dist[nh][nw] = dist[h][w]+1;
        }
    }

    /*
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) cout << dist[i][j] << ' ';
        cout << endl;
    }
    */
    if(dist[H-1][W-1]==-1) cout << -1 << endl;
    else cout << H*W-dist[H-1][W-1]-shapenum << endl;
    return 0;
}