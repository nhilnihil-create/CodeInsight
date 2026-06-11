#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int ans=0;
  vector<int> vec(5);
  rep(i,5){
    cin>>vec[i];
    ans+=(vec[i]+9)/10*10;
  }
  int cnt=ans;
  rep(i,5){
    if(vec[i]%10!=0)cnt=min(cnt,ans-10+vec[i]%10);
  }
  cout<<cnt<<endl;
}