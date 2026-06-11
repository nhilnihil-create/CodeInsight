#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,m,k,a,i,j,ans=0;
  cin>>n>>m;
  vector<int> c(m);
  for(i=0;i<n;i++){
    cin>>k;
    for(j=0;j<k;j++){
      cin>>a;
      c.at(a-1)++;
    }
  }
  for(i=0;i<m;i++) if(c.at(i)==n) ans++;
  cout<<ans<<endl;
}