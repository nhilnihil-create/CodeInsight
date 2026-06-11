#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;cin>>n>>m;
  if(n>=m){
    cout <<0<<endl;
    return 0;
  }
  vector<int>x(m);
  for(int i=0;i<m;i++){
    cin>>x.at(i);
  }
  sort(x.begin(),x.end());
  vector<int>l(m-1);
  for(int i=0;i<m-1;i++){
    l.at(i)=abs(x.at(i+1)-x.at(i));
  }
  int ans=x.at(m-1)-x.at(0);
  sort(l.rbegin(),l.rend());
  for(int i=0;i<n-1;i++){
    ans-=l.at(i);
  }
  cout <<ans<<endl;
}