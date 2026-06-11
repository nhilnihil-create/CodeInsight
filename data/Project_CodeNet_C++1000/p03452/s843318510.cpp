#include <bits/stdc++.h>
using namespace std;const int maxn = 2e6;int n ,p[maxn] ,w[maxn] ,m;
int dfs(int x){
    if(p[x]==x)return x;int q = p[x]; p[x] = dfs(q) , w[x]+= w[q];return p[x];
}
 main(){ios::sync_with_stdio(0) ,cin.tie(0) ,cout.tie(0);
   cin >> n >> m; for(int i=1;i<=n;i++)p[i]=i;
   while(m--){int l ,r ,d;   cin >> l >> r >> d;int x=dfs(l) ,y=dfs(r);if(x==y&&w[r]-w[l]!=d)return cout<<"No", 0;else p[y] = x ,w[y] = w[l]+d-w[r];}
   cout << "Yes";}
