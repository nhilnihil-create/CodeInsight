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
    int a=(vec[i]+9)/10*10;
    cnt+=a;
  }
  int ans=cnt;
  rep(i,5){
    int b=vec[i];
    b%=10;
    if(b!=0)ans=min(ans,cnt+b-10);
  }
  cout<<ans<<endl;
}