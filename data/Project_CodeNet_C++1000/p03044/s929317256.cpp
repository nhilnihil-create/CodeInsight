#include<bits/stdc++.h>
using namespace std;

vector<int> color;
void dfs(vector<vector<int>> &board, vector<vector<int>> &distance, int v){
    for(int j=0; j<board[v].size(); j++){
        int i=board[v][j];

        if(color[i] != -1){
            continue; //すでに色付けしてあるならスルー
        }
        if(distance[v][j] == 0){//もし距離が偶数なら同じ色
            color[i] = color[v];
            dfs(board, distance, i);
            continue;
        }
        if(distance[v][j] == 1){//もし距離が奇数なら違う色
            color[i] = 1 - color[v];
            dfs(board, distance, i);
            continue;
        }
    }
}

int main(){
    int N; cin >> N;

    vector<vector<int>> board(N+1);//つながっている橋
    vector<vector<int>> distance(N+1);//それぞれの距離

    for(int i=0; i<N-1; i++){
        int A, B, dis;
        cin >> A >> B >> dis;

        dis = dis%2; //偶数の時は０奇数の時は１となる

        board[A].push_back(B);
        board[B].push_back(A);

        distance[A].push_back(dis);
        distance[B].push_back(dis);
    }

    color.assign(N+1, -1);
    color[1] = 0;

    dfs(board, distance, 1);

    for(int i=1; i<=N; i++){
        cout << color[i] << endl;
    }
}