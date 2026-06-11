#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,k,b,q,r,ans=0;
  cin>>n>>k;
  if(k==0) cout<<n*n<<endl;
  else{
    for(b=k+1;b<=n;b++){
      q=n/b;
      r=n%b;
      ans+=q*(b-k);
      if(k<=r) ans+=r-k+1;
    }
    cout<<ans<<endl;
  }
}