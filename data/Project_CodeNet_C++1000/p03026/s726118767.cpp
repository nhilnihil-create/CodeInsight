#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
const ll MOD=1e9+7;

struct UnionFind{
    vector<int> par,rank;
    UnionFind(int n):par(n),rank(n,0){
        for(int i=0;i<n;++i) par[i]=i;
    }
    int root(int x){
        if(par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry) return ;
        if(rank[rx]>rank[ry]) par[ry]=rx;
        else par[rx]=ry;
        if(rank[rx]==rank[ry]) rank[ry]++;
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
    int cnt(int n){
        int res=0;
        for(int i=0;i<n;++i){
            if(root(i)==i) res++;
        }
        return res;
    }
};

int main(){
    int N;cin>>N;
    vector<int> a(N-1),b(N-1);
    vector<vector<int> > G(N);
    for(int i=0;i<N-1;++i){
        cin>>a[i]>>b[i];
        a[i]--;b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    vector<int> c(N);
    for(int i=0;i<N;++i) cin>>c[i];
    sort(c.begin(),c.end(),greater<int>());
    vector<int> res(N,0);
    queue<int> que;
    que.push(0);
    int i=0;
    while(!que.empty()){
        int p=que.front();que.pop();
        res[p]=c[i];
        i++;
        for(auto q:G[p]){
            if(res[q]>0) continue;
            que.push(q);
        }
    }
    int M=0;
    for(int i=1;i<N;++i) M+=c[i];
    cout<<M<<endl;
    for(int i=0;i<N;++i){
        cout<<res[i];
        if(i<N-1) cout<<' ';
    }
    cout<<endl;
    return 0;
}