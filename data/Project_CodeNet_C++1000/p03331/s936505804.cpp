#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  int ans=1e9;
  for(int i=1;i<n;i++){
    int a=i,b=n-i,cnt=0;
    while(a>0){
      cnt+=a%10;
      a/=10;
    }
    while(b>0){
      cnt+=b%10;
      b/=10;
    }
    ans=min(ans,cnt);
  }
  cout<<ans<<endl;
}