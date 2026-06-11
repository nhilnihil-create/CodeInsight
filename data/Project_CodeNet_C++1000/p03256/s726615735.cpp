#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const int MN = 2e5+5;
int N, M, i, x, y, a[MN], b[MN], c[MN], f, vis[MN];
string s;
queue<int> q;
vi adj[MN];
set<pii> e;

int main(){
    cin >> N >> M >> s;
    for(i=1;i<=M;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(i=1;i<=N;i++) c[i]=s[i-1]=='A';
    for(i=1;i<=N;i++){
        for(auto v : adj[i]){
            pii heh = make_pair(v,i);
            if(e.count(heh)) continue;
            e.insert(heh);
            if(c[i]==0) a[v]++;
            else b[v]++;
        }
    }
    for(i=1;i<=N;i++){
        if(!a[i]||!b[i]) q.push(i), vis[i]=1;
    }
    while(q.size()){
        x = q.front(); q.pop(); f++;
        for(auto v : adj[x]){
            pii kek = make_pair(v,x);
            if(!e.count(kek)) continue;
            e.erase(kek);
            if(c[x]==0) a[v]--;
            else b[v]--;
            if(!vis[v]&&(!a[v]||!b[v])){
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    printf("%s\n",f!=N?"Yes":"No");
    return 0;
}
