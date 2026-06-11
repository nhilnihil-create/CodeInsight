#include <bits/stdc++.h>
using namespace std;

#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define _dec(i,j,N) for(int i = (j-1);i >= 0;i--)
#define _dep(i,j,N) for(int i = (j);i >= 0;i--)
#define ALL(x) x.begin(),x.end()
#define pb push_back

typedef long long LL;
typedef pair<int,int> pii;

template<typename T>
ostream& operator<<(ostream &os,const vector<T> &vi){
    _for(i,0,vi.size()) os << vi[i] <<" ";
    os << endl;
    return os;
}
template<typename T>
ostream& operator<<(ostream &os,const set<T> &si){
    for(auto &a:si){
        os << a << " ";
    }
    os << endl;
    return os;
}
template<typename T1,typename T2>
ostream& operator<<(ostream &os,const map<T1,T2> mi){
    for(auto &a:mi){
        os << a.first<<" " << a.second <<endl;
    }
    return os;
}

const int maxn = 1e5+5;
int N,M,cnt;
vector<int> G[maxn];
map<int,int> mp;
int topo[maxn];
int vis[maxn];
int ans[maxn];

void dfs(int u){
    vis[u] = 1;
    for(auto a:G[u]){
        if(!vis[a]) dfs(a);
    }
    topo[cnt--] = u;
}

void dfs2(int u,int pre){
    vis[u] = 1;
    ans[u] = pre;
    _for(i,0,G[u].size()){
        if(!vis[G[u][i]]) dfs2(G[u][i],u);
    }
}

struct Cmp{
    bool operator()(const int &a,const int &b)const{
        int k = mp[a];
        int k2 = mp[b];
        return k < k2;
    }
};

int main()
{
    scanf("%d %d",&N,&M);
    _for(i,0,N+M-1){
        int a,b;
        scanf("%d %d",&a,&b);
        G[a].pb(b);
    }
    cnt = N;
    _rep(i,1,N){
        if(!vis[i])
            dfs(i);
    }
    _rep(i,1,N){
        mp[topo[i]] = i;
    }

    _rep(i,1,N){
        sort(ALL(G[i]),Cmp());
    }


    memset(vis,0,sizeof(vis));
    cnt = 1;
    dfs2(topo[1],0);

    _rep(i,1,N){
        printf("%d\n",ans[i]);
    }

    return 0;
}