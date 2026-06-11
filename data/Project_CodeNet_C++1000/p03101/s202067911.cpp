#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int H,W,h,w;
  cin>>H>>W>>h>>w;
  int ans=H*W-(h*W+w*H)+h*w;
  cout<<ans<<endl;
  return 0;
}