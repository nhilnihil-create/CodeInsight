#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N,M;
    cin>>N>>M;
    vector<map<int,bool>> tree(N);
    vector<int> incnt(N,0);
    rep(i,N+M-1){
        int A,B;
        cin>>A>>B;
        if(!tree[A-1][B-1]) incnt[B-1]++;
        tree[A-1][B-1]=true;
    }
    int root;
    rep(i,N) if(incnt[i]==0) root = i;
    queue<int> bfs;
    bfs.push(root);
    vector<int> parent(N);
    parent[root] = -1;
    vector<int> cnt(N,1);
    while(!bfs.empty()){
        int p = bfs.front();
        bfs.pop();
        for(auto nx:tree[p]){
            if(incnt[nx.first]==cnt[nx.first]){
                parent[nx.first] = p;
                bfs.push(nx.first);
            }
            else cnt[nx.first]++;
        }
    }
    rep(i,N) cout<<parent[i]+1<<endl;
}