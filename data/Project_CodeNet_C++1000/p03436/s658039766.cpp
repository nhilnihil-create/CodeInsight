#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

const int INF = 1e9;
int R,C;
vector<vector<char>> field;
vector<vector<int>> dist;
vector<pii> dirs = {pii(1,0), pii(-1,0), pii(0,1), pii(0,-1)};

bool bfs(){
    queue<pii> que;
    que.push(pii(0,0));
    dist.at(0).at(0) = 0;

    while(!que.empty()){
        auto q = que.front(); que.pop();
        int qr=q.first;
        int qc=q.second;
        int d = dist.at(qr).at(qc);

        for(auto dir : dirs){
            int nr = qr+dir.first;
            int nc = qc+dir.second;

            if(0<=nr && nr<R && 0<=nc && nc<C && field.at(nr).at(nc) == '.' && dist.at(nr).at(nc) == INF){
                que.push(pii(nr,nc));
                dist.at(nr).at(nc) = d+1;

                if(nr == R-1 && nc == C-1)return true;
            }
        }
    }

    return false;
}

void route(){
    int r=R-1, c=C-1;
    while(true){
        field.at(r).at(c) = '#';
        int d = dist.at(r).at(c);
        if(d<=0)break;
        for(auto dir : dirs){
            int nr = r+dir.first;
            int nc = c+dir.second;

            if(0<=nr && nr<R && 0<=nc && nc<C && dist.at(nr).at(nc) == d-1){
                r = nr; c= nc;
            }
        }
    }

}

int main(){
    cin >> R >> C;
    
    field = vector<vector<char>>(R, vector<char>(C));
    dist = vector<vector<int>>(R, vector<int>(C, INF));

    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++)cin >> field.at(r).at(c);
    }

    bool res = bfs();
    if(res){
        route();

        int count = 0;
        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
                if(field.at(r).at(c) == '.')count++;
            }
        }

        cout << count << endl;
    }else{
        cout << -1 << endl;
    }


}