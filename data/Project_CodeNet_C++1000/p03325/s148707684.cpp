#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  ll ans=0;
  rep(i,n){
    int a;cin>>a;
    while(1){
      if(a%2==1)break;
      a/=2;ans++;
    }
  }
  cout<<ans<<endl;
}