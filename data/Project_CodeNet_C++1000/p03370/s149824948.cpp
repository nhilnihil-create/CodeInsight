#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,x;cin>>n>>x;
  vector<int> vec(n);
  int cnt=0,ans=0;
  rep(i,n){
    ans++;
    cin>>vec[i];
    cnt+=vec[i];
  }
  sort(all(vec));
  x-=cnt;
  while(x>0){
    if(vec[0]>x)break;
    x-=vec[0];
    ans++;
  }
  cout<<ans<<endl;
}