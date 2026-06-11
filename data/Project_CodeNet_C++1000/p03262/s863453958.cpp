#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,x,b;
  cin >> n >> x;
  vector<int>zhy(n);
  for(int i=0;i<n;i++){
    cin >> b;
    zhy.at(i)=abs(b-x);
  }
  sort(zhy.begin(),zhy.end());
  int l=zhy.at(0),g,m=l,ans=l;
  for(int i=0;i<n;i++){
    g=zhy.at(i);
    l=zhy.at(0);
    while(g%l!=0){
      m=g%l;
      g=l;
      l=m;
    }
    ans=min(ans,m);
  }
  cout << ans << endl;
  return 0;
}