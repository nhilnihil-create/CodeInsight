#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N,k;
  cin >> N>>k;
  long ans;
  rep2(i,k+1,N+1){
    if(N%i==0){
      ans=ans+N/i*(i-k);
    }
    else{
      if(N%i-max(0,k-1)>=0){
        ans=ans+N/i*(i-k)+N%i-max(0,k-1);
      }
      else{
        ans=ans+N/i*(i-k);
      }
    }
  }
  
 
  cout<<ans<<endl;
 
}