#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define INF 1e18L+5
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
typedef vector<int> vi;
typedef pair<int,int>ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<long long > vl;
/*template<typename T>
void show(vector<T> v){
for(auto it:v){
    cout<<it<<" ";
}
cout<<"\n";
}/*
inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}
/*struct LCA{
    vi euleur,height,first,st;
    vector<bool> visited;
    LCA(vvi adj,int root=0){
        int n=adj.size();
        height.resize(n);visited.assign(n,false);euleur.reserve(2*n);
        first.resize(n);
        dfs(adj,root);
        int m=euleur.size();
        st.resize(4*m);
        build(1,0,m-1);
    }
    void dfs(vvi adj,int root=0,int h=0){
        visited[root]=true;
        height[root]=h;
        first[root]=(int)euleur.size();
        euleur.pb(root);
        for(int child:adj[root]){
            if(!visited[child]){
                dfs(adj,child,h+1);
                euleur.pb(root);
            }
        }
    }
    void build(int p,int l,int r){
        if(l==r)st[p]=euleur[l];
        else{
            int mid=(l+r)>>1;
            build(p<<1,l,mid);build(p<<1|1,mid+1,r);
            int l=st[p<<1],r=st[p<<1|1];
            st[p]=height[l]<height[r]?l:r;
        }
    }
    int query(int p,int l,int r,int i,int j){
        if (l> j || r < i)
            return -1;
        if(i<=l&&r<=j)return st[p];
        int mid=(l+r)>>1;
        int p1=query(p<<1,l,mid,i,j),p2=query(p<<1|1,mid+1,r,i,j);
        if(p1==-1)return p2;if(p2==-1)return p1;
        return height[p1]<height[p2]?p1:p2;
        
    }
    int lca(int u,int v){
        int l=first[u],r=first[v],m=euleur.size();
        if(l>r)swap(l,r);
        return query(1,0,m-1,l,r);
    }
};
*/
const int N=3000;

 int main() { ios_base::sync_with_stdio(false); cin.tie(NULL);
 int n;scanf("%d",&n);
 vector<double>dp(n+1);dp[0]=1;
 //dp[i] proba of having i heads 

for(int coin=0;coin<n;++coin){
    double p;
  scanf("%lf",&p);
    for(int i=coin+1;i>=0;--i){
        dp[i]=(i==0?0:dp[i-1]*p)+dp[i]*(1-p);
    }
}
double ans=0;
for(int i=0;i<=n;++i){
  int reste=n-i;
  if(reste<i){
      ans+=dp[i];
  }
}
printf("%.10lf\n",ans);
       return 0;
    }