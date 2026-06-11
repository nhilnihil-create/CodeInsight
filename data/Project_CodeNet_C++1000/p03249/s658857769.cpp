#pragma GCC optimiz(O2)

#include <bits/stdc++.h>

#define rg register
using namespace std;
typedef long long ll;

template<typename T>
inline bool read(T &n) {
    T ans = 0, flag = 1;
    char ch;
    while ((ch = getchar()) < '0' || ch > '9') if (ch == '-') flag = -1; else if (ch == EOF) return false;
    ans = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') ans = ans * 10 + ch - '0';
    n = ans * flag;
    return true;
}

inline ll read() {
    ll ans = 0, flag = 1;
    char ch;
    while ((ch = getchar()) < '0' || ch > '9') if (ch == '-') flag = -1;
    ans = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') ans = ans * 10 + ch - '0';
    return ans * flag;
};
const int maxn = 100005;
struct NODE {
    ll val, ord;
    bool operator<(NODE b) const {
        return val < b.val;
    }
} node[maxn];
struct EDGE{
    int nex,t;
}edge[maxn<<1];

int ecnt,head[maxn],siz[maxn],fa[maxn];
unordered_map<ll,int> unM;
inline void addedge(int u,int v){
    edge[++ecnt].nex=head[u];head[u]=ecnt;edge[ecnt].t=v;
    edge[++ecnt].nex=head[v];head[v]=ecnt;edge[ecnt].t=u;
}
ll dfs(int rt,int fa,int dis){
    ll ans=dis;
    for(rg int i=head[rt];i;i=edge[i].nex){
        int y=edge[i].t;
        if(y==fa) continue;
        ans+=dfs(y,rt,dis+1);
    }
    return ans;
}
int main() {
    int n;
    read(n);priority_queue<NODE> pq;
    for (rg int i = 1; i <= n; ++i) {
        siz[i] = 1;read(node[i].val);
        node[i].ord = i;
        pq.push(node[i]);
        unM[node[i].val]=i;
    }
    for(rg int i=n;i>=2;i--){
        NODE now=pq.top();pq.pop();
        if(unM.find(now.val+2*siz[now.ord]-n)==unM.end()){
            puts("-1");return 0;
        }
        fa[now.ord]=unM[now.val+2*siz[now.ord]-n];
        siz[fa[now.ord]]+=siz[now.ord];
        addedge(now.ord,fa[now.ord]);
    }
    if(siz[pq.top().ord]!=n||dfs(pq.top().ord,0,0)!=pq.top().val) puts("-1");
    else for(rg int i=1;i<=n;i++){
        if(fa[i]) cout<<i<<' '<<fa[i]<<endl;
    }
    return 0;
}