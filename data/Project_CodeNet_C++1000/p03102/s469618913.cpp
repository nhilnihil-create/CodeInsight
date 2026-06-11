#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,m,c,a,i,j,k,ans=0;
  cin>>n>>m>>c;
  vector<int> b(m);
  for(j=0;j<m;j++) cin>>b.at(j);
  for(i=0;i<n;i++){
    k=c;
    for(j=0;j<m;j++){
      cin>>a;
      k+=a*b.at(j);
    }
    if(k>0) ans++;
  }
  cout<<ans<<endl;
}
