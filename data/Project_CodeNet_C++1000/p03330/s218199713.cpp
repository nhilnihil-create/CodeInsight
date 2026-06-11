#include <bits/stdc++.h>
using namespace std;

const int N_MAX=500;
const int C_MAX=30;
int N,C;
vector<vector<int>> D(C_MAX,vector<int>(C_MAX,0));
vector<vector<int>> c(N_MAX,vector<int>(N_MAX,0));
vector<vector<int>> d(3,vector<int>(C_MAX,0));

int wro(int i,int j,int k){
  vector<int> dc={i,j,k};
  int res=0;
  for(int l=0;l<3;++l){
    for(int m=0;m<C;++m){
      res += d[l][m]*D[m][dc[l]];
    }
  }
  return res;
}

int main(){
  cin>>N>>C;
  for(int i=0;i<C;++i){
    for(int j=0;j<C;++j){
      cin>>D[i][j];
    }
  }
  for(int i=0;i<N;++i){
    for(int j=0;j<N;++j){
      cin>>c[i][j];
      --c[i][j];
      ++d[(i+j)%3][c[i][j]];
    }
  }

  int ans=INT_MAX;

  for(int i=0;i<C;++i){
    for(int j=0;j<C;++j){
      for(int k=0;k<C;++k){
        if(i!=j && j!=k && k!=i){
        ans=min(ans,wro(i,j,k));
        }
      }
    }
  }

  cout<<ans<<endl;
}