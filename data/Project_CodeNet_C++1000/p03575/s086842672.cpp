#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

struct Edge{
    int id;
    int to;
};
const int INF=1000000005;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<Edge>> to(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        to[a].push_back(Edge{i,b});
        to[b].push_back(Edge{i,a});
    }
    int ans=0;
    
    for(int i=0;i<m;i++){
        vector<int> dist(n,INF);
        dist[0]=0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(const auto& item:to[temp]){
                if(dist[item.to]!=INF||item.id==i) continue;
                dist[item.to]=dist[temp]+1;
                q.push(item.to);
            }
        }
        if(find(dist.begin(),dist.end(),INF)!=dist.end()){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}