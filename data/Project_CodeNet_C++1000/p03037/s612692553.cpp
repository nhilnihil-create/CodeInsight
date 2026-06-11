#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  int L=-1,R=1000001,ans;
  
  for(int i;i<m;i++){
    int l,r;
    cin>>l>>r;
    L=max(L,l);
    R=min(R,r);
  }
  
  ans=max(R-L+1,0);
  
  cout<<ans<<endl;
}
