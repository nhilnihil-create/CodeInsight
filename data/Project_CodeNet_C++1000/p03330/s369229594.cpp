#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int D[31][31];
const ll INF=1e9+7;

int main(){
  int n,c;
  cin>>n>>c;
  
  map<int,int> m1,m2,m0;
  for(int i=1;i<=c;i++){
    for(int j=1;j<=c;j++) cin>>D[i][j];
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      int x;
      cin>>x;
      if((i+j)%3==1) m1[x]++;
      else if((i+j)%3==2) m2[x]++;
      else m0[x]++;
    }
  }
  
  int ans=INF;
  for(int i=1;i<=c;i++){
    for(int j=1;j<=c;j++){
      if(j==i) continue;
      for(int k=1;k<=c;k++){
        if(k==i || k==j) continue;
        int sum=0;
        for(auto x:m1) sum+=D[x.first][i]*x.second;
        for(auto x:m2) sum+=D[x.first][j]*x.second;
        for(auto x:m0) sum+=D[x.first][k]*x.second;
        ans=min(ans,sum);
      }
    }
  }
  cout<<ans<<endl;
    
  return 0;
}