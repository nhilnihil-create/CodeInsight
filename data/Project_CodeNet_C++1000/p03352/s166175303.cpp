#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  int ans=1;
  for(int i=2;i<n+1;i++){
    int power=i*i;
    for(int j=2;;j++){
      if(power>n)break;
      ans=max(ans,power);
      power*=i;
    }
  }
  cout<<ans<<endl;
}