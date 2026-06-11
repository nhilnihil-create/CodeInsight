#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,d,x;cin>>n>>d>>x;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  int cnt=0;
  rep(i,n){
    int ans=1;
    while(1){
      if(ans>d)break;
      cnt++;
      ans+=a[i];
    }
  }
  cout<<cnt+x<<endl;
}