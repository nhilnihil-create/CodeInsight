#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int INF=1010000000000000017LL;
static const double eps=1e-12;
static const double pi=3.14159265358979323846;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};
static const int ddx[8]={1,-1,0,0,1,1,-1,-1};
static const int ddy[8]={0,0,1,-1,1,-1,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int N,M;
int X[100005],Y[100005],Z[100005];
vector<int> V[100005];

bool visited[100005];
int ans;

void bfs(int s){
    queue<int> que;
    que.push(s);
    visited[s]=true;
    while(que.size()){
        int p=que.front();
        que.pop();
        //cout<<p<<endl;
        for(auto u:V[p]){
            if(visited[u])continue;
            que.push(u);
            visited[u]=true;
        }
    }
}

signed main(){
    cin>>N>>M;
    for(int i=0;i<M;++i){
        cin>>X[i]>>Y[i]>>Z[i];
        X[i]--,Y[i]--;
        V[X[i]].push_back(Y[i]);
        V[Y[i]].push_back(X[i]);
    }
    priority_queue<PI> pq;
    for(int i=0;i<N;++i)pq.push(PI(V[i].size(),i));
    while(pq.size()){
        int p=pq.top().second;
        //cout<<pq.top().first<<endl;
        pq.pop();
        if(visited[p])continue;
        //cout<<p<<endl;
        bfs(p);
        ans+=1;
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
}