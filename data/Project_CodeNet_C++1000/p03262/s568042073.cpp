#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t gcc(int64_t a,int64_t b){
  while(b!=0){
    int64_t r=a%b;
    a=b;
    b=r;
  }
  return a;
}
int main(){
  int64_t n,x;
  cin >> n>>x;
  vector<int64_t> a(n),y(n);
  rep(i,n){
    cin >> a.at(i);
    y.at(i)=abs(x-a.at(i));
  }
  int64_t ans=1e10;
  rep(i,n-1){
    int64_t q=gcc(y.at(i),y.at(i+1));
    ans=min(ans,q);
  }
  if(n==1){
    cout << abs(y.at(0));
    return 0;
  }
  cout << ans;
}