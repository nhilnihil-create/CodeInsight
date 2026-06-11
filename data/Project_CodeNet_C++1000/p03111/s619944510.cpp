#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,a,b,c,i,j,k,m,mp,ans=-1;
  cin>>n>>a>>b>>c;
  vector<int> l(n);
  for(i=0;i<n;i++) cin>>l.at(i);
  for(i=0;i<(1<<(2*n));i++){
    j=i;
    vector<int> d(3);
    mp=0;
    for(k=0;k<n;k++){
      m=j%4;
      j/=4;
      if(m<3){
        if(d.at(m)>0) mp+=10;
        d.at(m)+=l.at(k);
      }
    }
    if(d.at(0)>0&&d.at(1)>0&&d.at(2)>0){
      mp+=abs(a-d.at(0))+abs(b-d.at(1))+abs(c-d.at(2));
      if(ans==-1||mp<ans) ans=mp;
    }
  }
  cout<<ans<<endl;
}