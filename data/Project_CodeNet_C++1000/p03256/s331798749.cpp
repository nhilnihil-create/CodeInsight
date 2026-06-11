#include <bits/stdc++.h>
using namespace std;

int N, M;
string S;
const int MAX = 400000;
vector<int> edges[MAX];
int visited[MAX];

void dfs(int i){
    visited[i] = -1;
    for(auto j : edges[i]){
        if(visited[j] == -1){
            cout << "Yes" << endl;
            exit(0);
        }else if(!visited[j]){
            dfs(j);
        }
    }
    visited[i] = 1;
}

int main(){
    int i, j, k;
    cin >> N >> M >> S;
    for(i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(S[a] == S[b]){
            edges[a].push_back(b+N);
            edges[b].push_back(a+N);
        }else{
            edges[a+N].push_back(b);
            edges[b+N].push_back(a);
        }
    }

    for(i=0; i<N; i++){
        if(!visited[i]) dfs(i);
    }
    cout << "No" << endl;
    return 0;
}