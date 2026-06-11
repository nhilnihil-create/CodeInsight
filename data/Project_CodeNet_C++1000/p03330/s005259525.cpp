#include <bits/stdc++.h>
using namespace std;

int main() {
  long N,C;
  cin>>N>>C;
  vector<vector<long>> d(C,vector<long>(C));
  vector<vector<long>> c(N,vector<long>(N));

  vector<long> c0(C);
  vector<long> c1(C);
  vector<long> c2(C);
  for(int i=0;i<C;i++) for(int j=0;j<C;j++) cin>>d[i][j];
  for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin>>c[i][j];
  for(int y=0;y<N;y++) for(int x=0;x<N;x++){
    if((x+y)%3==0) c0[c[x][y]-1]++;
    if((x+y)%3==1) c1[c[x][y]-1]++;
    if((x+y)%3==2) c2[c[x][y]-1]++;
  }
  long ans=123456789012345;
  for(int i=0;i<C;i++) for(int j=0;j<C;j++) for(int k=0;k<C;k++){
    if(i==j||j==k||k==i) continue;
    long tmp=0;
    for(int l=0;l<C;l++) tmp+=d[l][i]*c0[l];
    for(int l=0;l<C;l++) tmp+=d[l][j]*c1[l];
    for(int l=0;l<C;l++) tmp+=d[l][k]*c2[l];
    ans=min(ans,tmp);
  }
cout<<ans<<endl;
}
