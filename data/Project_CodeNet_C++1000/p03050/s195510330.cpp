#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long n;
  cin >>n;
  long ans=0;
  for(long i=1;i*i<n;i++){
    if(n%i==0){
      long a=n/i;
      if(n%(a-1)!=0){
        ans+=a-1;
      }
    }
  }
  
  
  cout<<ans<<endl;  
}

