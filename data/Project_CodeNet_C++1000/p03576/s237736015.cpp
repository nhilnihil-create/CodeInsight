#include <bits/stdc++.h>
using namespace std;


int main() {
  int K,N;
  cin>>N>>K;
  int64_t Z=4167167167167167167;
  vector<int64_t> p(N+1);
  vector<int64_t> q(N+1);
  for(int i=0;i<N;i++){
    cin>>p[i]>>q[i];
  }
  p[N]=-2001167167;
  q[N]=-2001167167;
  vector<int64_t> x=p;
  vector<int64_t> y=q;
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  vector<vector<int>> rui(N+1,vector<int>(N+1));
  for(int i=0;i<N;i++){
    int a=lower_bound(x.begin(),x.end(),p[i])-x.begin();
    int b=lower_bound(y.begin(),y.end(),q[i])-y.begin();
    rui[a][b]=1;
  }
  for(int i=0;i<=N;i++){
    for(int j=0;j<N;j++){
      rui[i][j+1]+=rui[i][j];
    }
  }
  for(int i=0;i<=N;i++){
    for(int j=0;j<N;j++){
      rui[j+1][i]+=rui[j][i];
    }
  }
  for(int i=0;i<N;i++){
    for(int j=i+1;j<=N;j++){
      for(int k=0;k<N;k++){
        for(int l=k+1;l<=N;l++){
          if(K<=rui[j][l]+rui[i][k]-rui[j][k]-rui[i][l]){
            Z=min(Z,(x[j]-x[i+1])*(y[l]-y[k+1]));
          }
        }
      }
    }
  }
  cout<<Z<<endl;    
}