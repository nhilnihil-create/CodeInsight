#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char> (w));
    int maxWhite = 0;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> s.at(i).at(j);
            if(s.at(i).at(j) == '.'){
                maxWhite++;
            }//白いマスの数
        }
    }
    //cout << maxWhite << endl;

    vector<vector<int>> dist(h, vector<int> (w, -1));
    queue<pair<int, int>> que;
    dist.at(0).at(0) = 0;
    que.push(make_pair(0, 0));//初期は訪問済み
    //bool flag = true;
    while(!que.empty()){//幅優先探索
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        /*if(dist.at(x).at(y) != -1){
            continue;
        }//探索済みなら探索しない*/

        if(x + 1 >= 0 && y >= 0  && x + 1 < h && y < w && s.at(x + 1).at(y) != '#'){
            if(dist.at(x + 1).at(y) == -1){
                dist.at(x + 1).at(y) = dist.at(x).at(y) + 1;
                que.push(make_pair(x + 1, y));
            }//探索済みなら探索しない
        }
        if(x - 1 >= 0 && y >= 0  && x - 1 < h && y < w && s.at(x - 1).at(y) != '#'){
            if(dist.at(x - 1).at(y) == -1){
                dist.at(x - 1).at(y) = dist.at(x).at(y) + 1;
                que.push(make_pair(x - 1, y));
            }//探索済みなら探索しない
        }
        if(x >= 0 && y + 1 >= 0  && x < h && y + 1 < w && s.at(x).at(y + 1) != '#'){
            if(dist.at(x).at(y + 1) == -1){
                dist.at(x).at(y + 1) = dist.at(x).at(y) + 1;
            que.push(make_pair(x, y + 1));
            }//探索済みなら探索しない 
        }
        if(x >= 0 && y - 1 >= 0  && x < h && y - 1 < w && s.at(x).at(y - 1) != '#'){
            if(dist.at(x).at(y - 1) == -1){
                dist.at(x).at(y - 1) = dist.at(x).at(y) + 1;
                que.push(make_pair(x, y - 1));
            }//探索済みなら探索しない
        }

        /*if(x + 1 >= 0 && y + 1 >= 0  && x + 1 < h && y + 1 < w && s.at(x + 1).at(y + 1) != '#'){
            if(dist.at(x + 1).at(y + 1) != -1){
                continue;
            }//探索済みなら探索しない
            dist.at(x + 1).at(y + 1) = dist.at(x).at(y) + 1;
            que.push(make_pair(x + 1, y + 1));
        }
        if(x + 1 >= 0 && y - 1 >= 0  && x + 1 < h && y - 1 < w && s.at(x + 1).at(y - 1) != '#'){
            if(dist.at(x + 1).at(y - 1) != -1){
                continue;
            }//探索済みなら探索しない
            dist.at(x + 1).at(y - 1) = dist.at(x).at(y) + 1;
            que.push(make_pair(x + 1, y - 1));
        }
        if(x - 1 >= 0 && y + 1 >= 0 && x - 1 < h && y + 1 < w && s.at(x - 1).at(y + 1) != '#'){
            if(dist.at(x - 1).at(y + 1) != -1){
                continue;
            }//探索済みなら探索しない    
            dist.at(x - 1).at(y + 1) = dist.at(x).at(y) + 1;
            que.push(make_pair(x - 1, y + 1));
        }
        if(x - 1 >= 0 && y - 1 >= 0 && x - 1 < h && y - 1 < w && s.at(x - 1).at(y - 1) != '#'){
            if(dist.at(x - 1).at(y - 1) != -1){
                continue;
            }//探索済みなら探索しない
            dist.at(x - 1).at(y - 1) = dist.at(x).at(y) + 1;
            que.push(make_pair(x - 1, y - 1));
        }*/
    }

    /*for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << dist.at(i).at(j) << endl;
        }
    }*/
    if(dist.at(h - 1).at(w - 1) == -1){
        cout << -1 << endl;
    }else{
        maxWhite -= dist.at(h - 1).at(w - 1) + 1;
        cout << maxWhite << endl;
    }

}
