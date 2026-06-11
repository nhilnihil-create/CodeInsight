#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  vector<int> vec(5);
  int cnt=0;
  rep(i,5){
    cin>>vec[i];
    cnt+=(vec[i]+9)/10*10;
  }
  bool bl=true;
  int ans=1e9,a=0;
  rep(i,5){
    if(vec[i]%10!=0){
      bl=false;
      a=vec[i]%10;
    }
    ans=min(ans,a);
  }
  if(bl)cout<<cnt<<endl;
  else cout<<cnt-10+ans<<endl;
}