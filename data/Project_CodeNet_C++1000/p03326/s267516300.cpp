#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int64_t>> c(n,vector<int64_t>(8));
  int64_t b=0;
  for(int i=0;i<n;i++){
    vector<int64_t> xyz(3);
    cin>>xyz.at(0)>>xyz.at(1)>>xyz.at(2);
    b+=abs(xyz.at(0))+abs(xyz.at(1))+abs(xyz.at(2));
    for(int j=0;j<8;j++){
      int k=j;
      int64_t s=0;
      for(int d=0;d<3;d++){
        s+=xyz.at(d)*(k%2==0?1:-1);
        k/=2;
      }
      c.at(i).at(j)=s;
    }
  }
  int64_t a=0;
  for(int x=0;x<8;x++){
    vector<vector<int64_t>> p(n+1,vector<int64_t>(m+1,-b));
    for(int i=0;i<=n;i++)
      p[i][0]=0;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m&&j<=i;j++)
        p[i][j]=max(p[i-1][j],p[i-1][j-1]+c.at(i-1).at(x));
    a=max(a,p[n][m]);
  }
  cout<<a<<endl;
}