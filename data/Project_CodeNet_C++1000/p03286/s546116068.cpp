#include<bits/stdc++.h>
using namespace std;

signed main(){

  int64_t n;
  cin>>n;

  if(n==0){cout<<0<<endl;return 0;}

  string ans = "";

  while(n){
    int r = abs(n%2);
    n -= r;
    n /= -2;
    ans += to_string(r);
  }
  reverse(begin(ans),end(ans));
  cout<<(ans)<<endl;

}