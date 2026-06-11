#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,dt,dl;
  cin>>n;
  vector<int> t(n+1),x(n+1),y(n+1);
  for(i=1;i<=n;i++){
    cin>>t.at(i)>>x.at(i)>>y.at(i);
    dt=t.at(i)-t.at(i-1);
    dl=abs(x.at(i)-x.at(i-1))+abs(y.at(i)-y.at(i-1));
    if(dl<=dt&&(dl-dt)%2==0) continue;
    else{
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}