#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#include<list>
#include<limits>
#include<bitset>
#include<ctype.h>
#include<set>
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
const ll MOD=10007;
const ll INF=1000000000;
const int MAX=100001;
typedef pair<int,int> P;
int d[100010];
vector<edge> G[100010];
void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P>> que;
    fill(d,d+100010,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top();
        que.pop();
        int v=p.second;
        if(d[v]<p.first){
            continue;
        }
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        G[i].push_back({(i+1)%k,1});
        G[i].push_back({(i*10)%k,0});
    }
    dijkstra(1);
    cout<<d[0]+1<<endl;
}

                           
