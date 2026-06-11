#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int mod=1000000007;
int main() {
  long k,a,b;
  cin >> k>>a>>b;
  long ans=0;
  if(a+1<b){
    if(k>a){
      k-=a-1;
      ans=a+k/2*(b-a)+k%2;
    }
    else{
      ans=k+1;
    }
  }
  else{
    ans=k+1;
  }
  cout<<ans<<endl;  
}