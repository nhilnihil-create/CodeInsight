#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,X,Y,mn=10000,mx=-1;
  cin>>n>>m>>X>>Y;
  vector<int>x(n);
  for(int i=0;i<n;i++){
    cin>>x[i];
  }
  vector<int>y(m);
  for(int i=0;i<m;i++){
    cin>>y[i];
  }
  for(int i=0;i<m;i++){
    mn=min(mn,y[i]);
  }
  for(int i=0;i<n;i++){
    mx=max(mx,x[i]);
  }
  if(mx<mn&&X<Y&&mx<Y&&X<mn){
    cout<<"No War"<<endl;
  }
  else{
    cout<<"War"<<endl;
  }
}
  
