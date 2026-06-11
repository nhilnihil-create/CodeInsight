#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int cnt=0;
  vector<int> vec(5);
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