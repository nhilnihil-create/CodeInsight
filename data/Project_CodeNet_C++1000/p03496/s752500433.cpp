#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,i,mi=1e6+1,ma=-1e6-1,mii=-1,mai=-1;
  cin>>n;
  for(i=1;i<=n;i++){
    cin>>a;
    if(a<mi){
      mi=a;
      mii=i;
    }
    if(a>ma){
      ma=a;
      mai=i;
    }
  }
  cout<<2*n<<endl;
  if(abs(mi)<=abs(ma)){
    cout<<mai<<' '<<1<<endl<<mai<<' '<<1<<endl;
    for(i=1;i<n;i++) cout<<i<<' '<<i+1<<endl<<i<<' '<<i+1<<endl;
  }
  else if(abs(mi)>abs(ma)){
    cout<<mii<<' '<<n<<endl<<mii<<' '<<n<<endl;
    for(i=n;i>1;i--) cout<<i<<' '<<i-1<<endl<<i<<' '<<i-1<<endl;
  }
}