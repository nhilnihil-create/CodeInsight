#include<iostream>
#include<vector>
using namespace std;

int N;
vector<pair<int,int> > G[100001];

bool visited[100001];
int col[100001];

void dfs(int v){
    pair<int,int> pa;
    int ta,we;
    int i;
    for(i=0; i<G[v].size(); i++){
        pa=G[v][i];
        ta=pa.first;
        we=pa.second;
        if(visited[ta]==0){
            visited[ta]=1;
            if(we==1){
                col[ta]=(!col[v]);
            }else{
                col[ta]=col[v];
            }
            dfs(ta);
        }
    }
}

int main(){
    //input
    cin >> N;
    int u,v,w;
    int i;
    for(i=0; i<N-1; i++){
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v,w%2));
        G[v].push_back(make_pair(u,w%2));
    }

    //calc
    fill(visited,visited+N+1,0);
    visited[1]=1;
    col[1]=1;
    dfs(1);

    //output
    for(i=1; i<=N; i++){
        cout << col[i] << endl;
    }
    system("pause");
    return 0;
}