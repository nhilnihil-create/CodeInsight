#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,k;cin>>n>>k;
  int cnt=0;
  for(int i=1;i<=n;i+=2)cnt++;
  if(cnt>=k)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}