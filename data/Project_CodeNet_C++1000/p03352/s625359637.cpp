#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int x;cin>>x;
  int ans=1;
  for(int i=2;i<=sqrt(x);i++){
    int a=1;
    while(a<=x){
      ans=max(ans,a);
      a*=i;
    }
  }
  cout<<ans<<endl;
}