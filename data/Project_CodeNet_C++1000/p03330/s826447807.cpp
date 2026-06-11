#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,c,i,j,k,z;scanf("%d%d",&n,&c);
  int d[c][c],s[3][c];
  for(i=0;i<3;i++){
    for(j=0;j<c;j++) s[i][j] = 0;
  }
  for(i=0;i<c;i++){
    for(j=0;j<c;j++) scanf("%d",&d[i][j]);
  }
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      scanf("%d",&z);
      for(k=0;k<c;k++) s[(i+j)%3][k] += d[z-1][k];
    }
  }
  vector<vector<pair<int,int>>> m(3,vector<pair<int,int>>(c));
  for(i=0;i<3;i++){
    for(j=0;j<c;j++){
      m[i][j].first = s[i][j];m[i][j].second = j;
    }
  }
  for(i=0;i<3;i++) sort(m[i].begin(),m[i].end());
  long long ans = 1000000000000;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      for(k=0;k<3;k++){
        if(m[0][i].second != m[1][j].second && m[0][i].second != m[2][k].second && m[1][j].second != m[2][k].second) ans = min(ans,(long long)(m[0][i].first+m[1][j].first+m[2][k].first));
      }
    }
  }
  printf("%lld\n",ans);
}