#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,x=0,y=0;
  cin>>n;
  vector<int>p(n);
  for(int i=0;i<n;i++){
    cin>>p[i];
    y+=p[i];
  }
  for(int i=0;i<n;i++){
    x=max(x,p[i]);
  }
  if(x>=y-x){
    cout<<"No"<<endl;
  }
  else{
    cout<<"Yes"<<endl;
  }
}