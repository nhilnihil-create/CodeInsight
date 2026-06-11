#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int>t(N+1);
  vector<int>x(N+1);
  vector<int>y(N+1);
  t[0]=0;
  x[0]=0;
  y[0]=0;
  for(int i=1;i<N+1;i++){
    cin>>t[i]>>x[i]>>y[i];
  }
  bool flag=true;
  for(int i=1;i<N+1;i++){
    int l=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
    int T=t[i]-t[i-1];
    if(l%2!=T%2){
      flag=false;
    }
    if(l>T){
      flag=false;
    }
  }
  if(flag){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
