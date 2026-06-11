#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[50],b[50];

bool g[50][50];
bool v[50];

void dfs(int nv){
  v[nv]=true;
  for(int v2=0;v2<n;++v2){
    if(g[nv][v2]==false) continue;
    if(v[v2]==true) continue;

    dfs(v2);
  }
}

int main(){
  cin >> n >> m;
  for(int i=0;i<m;++i){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    g[a[i]][b[i]]=g[b[i]][a[i]]=true;
  }
  int ans=0;

  for(int i=0;i<m;++i){
    g[a[i]][b[i]]=g[b[i]][a[i]]=false;

    for(int j=0;j<n;++j) v[j]=false;

    dfs(0);

    bool br=false;

    for(int j=0;j<n;++j) if(v[j]==false) br=true;
    if(br) ans+=1;

    g[a[i]][b[i]]=g[b[i]][a[i]]=true;
  }
  cout << ans << endl;
  return 0;
}
