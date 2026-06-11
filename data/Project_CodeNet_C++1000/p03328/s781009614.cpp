#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int a,b;cin>>a>>b;
  int ans=0;
  for(int i=1;i<=b-a;i++){
    ans+=i;
  }
  cout<<ans-b<<endl;
}