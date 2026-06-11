#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x,i,ans=0;
  cin>>n>>x;
  vector<int> m(n);
  for(i=0;i<n;i++){
    cin>>m.at(i);
    x-=m.at(i);
    ans++;
  }
  sort(m.begin(),m.end());
  ans+=x/m.at(0);
  cout<<ans<<endl;
}