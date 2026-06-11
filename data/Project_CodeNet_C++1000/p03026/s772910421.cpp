#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<vector<int> > edge(N);
    int a, b;
    for(int i=0;i<N-1;++i){
        cin>>a>>b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> c(N);
    for(int i=0;i<N;++i){
        cin>>c[i];
    }
    sort(c.begin(), c.end(), greater<int>());

    int par[N];
    par[0] = 0;
    for(int i=1;i<N;++i){
        par[i] = -1;
    }
    queue<int> que;
    que.push(0);
    int state;
    while(!que.empty()){
        state = que.front();que.pop();
        for(int i=0;i<edge[state].size();++i){
            if(par[edge[state][i]]!=-1)continue;
            par[edge[state][i]] = state;
            que.push(edge[state][i]);
        }
    }
    int anstree[N];
    int ans = 0;
    for(int i=1;i<N;++i){
        ans += c[i];
    }
    vector<vector<int> > children(N);
    for(int i=1;i<N;++i){
        children[par[i]].push_back(i);
    }
    que.push(0);
    int num = 0;
    while(!que.empty()){
        state = que.front();que.pop();
        anstree[state] = c[num];
        num++;
        for(int i=0;i<children[state].size();++i){
            que.push(children[state][i]);
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<N;++i){
        cout<<anstree[i]<<" ";
    }
    cout<<endl;
}
