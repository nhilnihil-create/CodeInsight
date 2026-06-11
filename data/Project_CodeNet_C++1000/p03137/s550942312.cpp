#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int>x(m);
  for(int i=0;i<m;i++){
    cin>>x[i];
  }
  sort(x.begin(),x.end());
  vector<int>d(m);
  for(int i=0;i<m-1;i++){
    d[i]=x[i+1]-x[i];
  }
  sort(d.begin(),d.end());
  for(int i=0;i<n-1;i++){
    d.pop_back();
  }
  int num=0;
  for(int i=0;i<m-n+1;i++){
    num+=d[i];
  }
  cout<<num<<endl;
}
  