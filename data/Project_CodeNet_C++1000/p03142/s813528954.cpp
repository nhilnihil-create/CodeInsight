#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())//vectorの降順ソート
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define LINF 1e18
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;
//typedef tuple<ll, ll, ll> T;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

vector<int> edges[101010],from[101010];
int indeg[101010];
int dist[101010],par[101010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;cin>>N>>M;
    REP(i,N-1+M){
        int a,b;
        cin>>a>>b;
        indeg[b]++;
        edges[a].push_back(b);
        from[b].push_back(a);
    }
    int root=-1;
    for(int i=1;i<=N;i++) if(indeg[i]==0) root=i;
    par[root]=0;
    dist[root]=0;
    queue<int> que;
    que.push(root);
    while(que.size()){
        int i=que.front();que.pop();
        for(int j:from[i]){
            if(dist[j]+1>dist[i]){
                par[i] = j;
                dist[i] = dist[j]+1;
            }
        }
        for(int j:edges[i]){
            indeg[j]--;
            if(indeg[j]==0) que.push(j);
        }
    }
    for(int i=1;i<=N;i++) cout<<par[i]<<endl;
}
