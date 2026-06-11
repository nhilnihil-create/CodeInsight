#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,d,x;cin>>n>>d>>x;
  vector<int>a(n+1);
  for(int i=1;i<=n;i++)cin>>a[i];
  int cnt=0;
  for(int i=1;i<=n;i++){
    int ans=1;
    for(int j=1;;j++){
      if(ans>d)break;
      cnt++;
      ans=j*a[i]+1;
    }
  }
  cout<<cnt+x<<endl;
}