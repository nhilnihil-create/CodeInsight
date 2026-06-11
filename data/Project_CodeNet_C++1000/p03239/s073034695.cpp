#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,T,mi=1001;
  cin>>N>>T;
  for(int i=0;i<N;i++){
    int c,t;
    cin>>c>>t;
    if(t<=T)
      mi=min(mi,c);
  }
  if(mi==1001)
    cout<<"TLE"<<endl;
  else
    cout<<mi<<endl;
}