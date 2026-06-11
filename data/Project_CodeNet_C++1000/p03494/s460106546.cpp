#include<bits/stdc++.h>
using namespace std;

int main(){
  int N; cin>>N;
  int a[N];
  for(int i=0; i<N; i++)cin>>a[i];
  int cnt=0;
  while(1){
    bool ndiv=false;
    for(int i=0; i<N; i++){
      if(a[i]%2!=0)ndiv=true;
      if(a[i]%2==0)a[i]/=2;
    }
    if(ndiv)break;
    cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}
  
