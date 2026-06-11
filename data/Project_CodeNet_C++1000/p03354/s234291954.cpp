#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;


typedef pair<int,int> pa;

int fa[N];

int _find(int root)
{
     if(fa[root]==root)
        return root;
     return fa[root]=_find(fa[root]);
}
int p[N];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
     int n,m;
     cin>>n>>m;
     for(int i=1;i<=n;i++) fa[i]=i;

     for(int i=1;i<=n;i++){
        cin>>p[i];
     }
     for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        int xx=_find(x);
        int yy=_find(y);
        if(xx!=yy){
            fa[xx]=yy;
        }
     }
  //   cout<<10<<endl;
     int ans=0;
     for(int i=1;i<=n;i++){
            int x=_find(i);
            int y=_find(p[i]);
        if(x == y) ans++;
     }
     cout<<ans<<endl;
    return 0;
}
