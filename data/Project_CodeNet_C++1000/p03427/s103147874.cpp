#include<bits/stdc++.h>
using namespace std;

signed main(){

  int64_t n;
  cin>>n;

  auto count = [](int64_t n){
    int res = 0;
    while(n){
      res+=n%10;
      n/=10;
    }
    return res;
  };

  if(n<1e6){
    int ans = 0;
    for(int i=0;i<=n;++i)ans = max(ans,count(i));
    cout<<(ans)<<endl;
    return 0;
  }

  int ans = 0;
  for(int i=0;i<1e6;++i)ans = max(ans,count(n-i));
  int dig = to_string(n).size()-1;
  int64_t tmp = to_string(n)[0]-'0'-1;
  for(int i=0;i<dig;++i)tmp = tmp*10+9;
  for(int64_t i=-1e6;i+tmp<=n&&i<1e6;++i)ans = max(ans,count(i+tmp));
  cout<<(ans)<<endl;

}