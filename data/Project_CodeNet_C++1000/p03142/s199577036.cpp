#include<bits/stdc++.h>
using namespace std;

static const int MAX=1e5+1;
static const int INF=1e8;

int N;
vector<vector<int>> g(MAX); //有向グラフの隣接リスト
vector<int> out; //頂点をトポロジカルソートした配列
bool used[MAX]={};
int ind[MAX];
vector<int> dist(MAX,0);

void bfs(int s){
    queue<int> q;
    q.push(s);
    used[s]=true;
    dist[s]=0;
    while(!q.empty()){
        int u=q.front(); q.pop();
        out.push_back(u);
        for(auto it=g[u].begin();it!=g[u].end();it++){
            int v=*it;
            ind[v]--;
            dist[v]=max(dist[u]+1,dist[v]);
            if(ind[v]==0&&used[v]==false){ //入次数が0になったら追加
                used[v]=true; //再訪しない
                q.push(v);
            }
        }
    }
}

void tsort(){
    for(int i=0;i<N;i++){
        ind[i]=0;
    }
    for(int u=0;u<N;u++){
        for(auto it=g[u].begin();it!=g[u].end();it++){
            int v=*it;
            ind[v]++; //各頂点の次数を計算
        }
    }
    for(int u=0;u<N;u++){
        if(ind[u]==0&&used[u]==false) bfs(u);
    }
    //for(int i=0;i<out.size();i++){
        //cout << out[i] << endl;
    //}
}

int main(){
    cin >> N;
    int M; cin >> M;
    int a[N-1+M],b[N-1+M];
    for(int i=0;i<N-1+M;i++){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        g[a[i]].push_back(b[i]);
    }
    tsort();
    int ans[N]={};
    for(int i=0;i<N-1+M;i++){
        if(dist[b[i]]-dist[a[i]]==1){
            ans[b[i]]=a[i]+1;
        }
    }
    for(int i=0;i<N;i++){
        cout << ans[i] << endl;
    }
    
}
