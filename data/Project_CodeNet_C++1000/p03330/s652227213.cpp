#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n,C;
  cin >> n >> C;
  vector<vector<int>> d(C,vector<int>(C));
  for(int i=0;i<C;++i){
    for(int j=0;j<C;++j) cin >> d[i][j];
  }

  vector<vector<int>> c(n,vector<int>(n));

  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      cin >> c[i][j];
      c[i][j]--;
    }
  }

  vector<vector<int>> cost(3,vector<int>(C,0));

  for(int k=0;k<C;++k){
    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
        cost[(i+j)%3][k] += d[c[i][j]][k];
      }
    }
  }

  int cal=1<<30;
  int co[3];
  for(co[0]=0;co[0]<C;++co[0]){
    for(co[1]=0;co[1]<C;++co[1]){
      if(co[0]==co[1])continue;
      for(co[2]=0;co[2]<C;++co[2]){
        if(co[2]==co[0] || co[2]==co[1])continue;
        int tmp=0;
        for(int l=0;l<3;++l)tmp += cost[l][co[l]];

        cal=min(cal,tmp);
      }
    }
  }
  cout << cal << endl;
  return 0;
}
