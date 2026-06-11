#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,m,n) for(int i=m;i<n;i++)

int main() {
  int m,k;
  cin>>m>>k;
  if(m==0){
    if(k==0){
      cout<<0<<endl;
      cout<<0<<endl;
    }
    else{
      cout<<-1<<endl;
    }
  }
  else if(m==1){
    if(k==0){
      cout<<0<<endl;
      cout<<0<<endl;
      cout<<1<<endl;
      cout<<1<<endl;
    }
    else{
      cout<<-1<<endl;
    }
  }
  else{
    if(k<(1<<m)){
      rep(i,0,(1<<m)){
        if(i!=k){
          cout<<i<<endl;
        }
      }
      cout<<k<<endl;
      for(int i=(1<<m)-1;i>=0;i--){
        if(i!=k){
          cout<<i<<endl;
        }
      }
      cout<<k<<endl;
    }
    else{
      cout<<-1<<endl;
    }
  }
}