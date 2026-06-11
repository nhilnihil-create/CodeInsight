#include<vector>
#include<stdio.h>
#include<iostream>
using namespace std;

vector<pair<int,int>> g[100001];
int diks[100001];
bool is_checked[100001];
bool is_reached[100001];

bool is_root(int a){
    if(is_checked[a]) {
        return true;
    } else is_checked[a] = true;
    
    for(int i = 0; i < g[a].size(); i++){
        if(is_reached[ g[a][i].first ]){
            if(diks[ g[a][i].first ] != diks[a] + g[a][i].second){
                return false;
            }
        }
        diks[ g[a][i].first ] = diks[a] + g[a][i].second;
        is_reached[ g[a][i].first ] = true;
        if(!is_root(g[a][i].first)) return false;
    }
    return true;
}

int main(){
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++){
        int L, R, D; cin >> L >> R >> D;
        g[L-1].push_back(pair<int,int>(R-1, D));
        g[R-1].push_back(pair<int,int>(L-1, -D));
    }
    for(int i = 0; i < N; i++){
        is_checked[i] = false;
        is_reached[i] = false;
    }
    
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < g[i].size(); j++){
    //         cout << g[i][j].first;
    //     } cout << endl;
    // }
    for(int i = 0; i < N; i++){
        diks[i] = 0;
        if(!is_root(i)) {
            cout << "No";
            return 0;
        }
    } cout << "Yes";
    
    return 0;
}

