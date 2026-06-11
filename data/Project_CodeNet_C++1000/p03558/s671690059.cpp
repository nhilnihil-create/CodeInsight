#include<bits/stdc++.h>
using namespace std;

const int INF=1e8;

int main(){
    int k;
    cin>>k;
    vector<int> dist(k,INF);
    vector<int> used(k,0);
    dist[1]=1;
    deque<int> que;
    que.push_front(1);
    while(!que.empty()){
        int v=que.front();
        que.pop_front();
        if(used[v]) continue;
        used[v]=true;
        int forward=(v+1)%k;
        if(dist[forward]>dist[v]+1){
            dist[forward]=dist[v]+1;
            que.push_back(forward);
        }
        int jump=(v*10)%k;
        if(dist[jump]>dist[v]){
            dist[jump]=dist[v];
            que.push_front(jump);
        }
    }
    cout<<dist[0]<<endl;
    return 0;
}