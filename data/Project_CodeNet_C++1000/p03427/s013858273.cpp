#include<bits/stdc++.h>
using namespace std;

signed main(){

  int64_t n;
  cin>>n;

  auto digit_sum = [](int64_t n){
    int res = 0;
    while(n){
      res+=n%10;
      n/=10;
    }
    return res;
  };

  int dig = to_string(n).size()-1;
  int64_t tmp = to_string(n)[0]-'0'-1;
  for(int i=0;i<dig;++i)tmp = tmp*10+9;
  int ans = max(digit_sum(n),digit_sum(tmp));
  cout<<(ans)<<endl;

}