#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define co(n) cout<<n<<endl
using namespace std;

int main(){ 
  int n;
  cin>>n;
  int c=0,d=0,ans=10000,a,b,x,y;
  int aa[n];
  rep(i,0,n) cin>>aa[i];
  rep(i,0,n-1){
    if(aa[i]==aa[i+1]) c++;
    else{
      d+=(c+1)/2;
      c=0;
    }
  }
  d+=(c+1)/2;
  
  co(d);
  
  return 0;
}