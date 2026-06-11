#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int m,k;
  cin>>m>>k;
  if(m==0){
    cout<<(k==0?"0 0":"-1")<<endl;
  }
  else if(m==1){
    cout<<(k==0?"0 0 1 1":"-1")<<endl;
  }
  else{
    if(k>=(1<<m))cout<<-1<<endl;
    else{
      for(int i=0; i<(1<<m); ++i)if(i!=k)cout<<i<<" ";
      cout<<k<<" ";
      for(int i=(1<<m)-1; i>=0; --i)if(i!=k)cout<<i<<" ";
      cout<<k<<endl;
    }
  }
}