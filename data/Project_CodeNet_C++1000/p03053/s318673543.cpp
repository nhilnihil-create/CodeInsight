#include<bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

const int INF = 1e9;
int R,C;
vector<vector<char>> field;
vector<vector<int>> depth;

int getMaxDepth(){
    int res = 0;
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++)res = max(depth.at(r).at(c), res);
    }
    return res;
}

void bfs(queue<pii> blacks){
    queue<pii> que;
    vector<pii> dirs = {pii(1,0), pii(-1,0), pii(0,1), pii(0,-1)};

    while(!blacks.empty()){
        pii bl = blacks.front(); blacks.pop();

        int r = bl.first;
        int c = bl.second;
        depth.at(r).at(c) = 0;

        que.push(bl);
    }

    while(!que.empty()){
        auto q = que.front(); que.pop();
        int d = depth.at(q.first).at(q.second);

        for(auto dir : dirs){
            int nr = q.first + dir.first;
            int nc = q.second + dir.second;

            if(0<=nr && nr<R && 0<=nc && nc<C && depth.at(nr).at(nc) == INF){
                depth.at(nr).at(nc) = d+1;
                que.push(pii(nr,nc));
            }
        }
    }
}

int main(){
    cin >> R >> C;

    queue<pii> blacks;
    field = vector<vector<char>>(R, vector<char>(C));
    depth = vector<vector<int>>(R, vector<int>(C, INF));
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            char ch;
            cin >> ch;
            field.at(r).at(c) = ch;
            if(ch == '#')blacks.push(pii(r,c));
        }
    }

    bfs(blacks);

    cout << getMaxDepth() << endl;
}