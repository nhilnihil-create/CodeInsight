#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  map<int,int64_t> mp;
  mp[0]++;
  int64_t sum = 0;
  while(n--){
    int a;cin>>a;
    sum += a;
    sum %= k;
    mp[sum]++;
  }
  int64_t ans = 0;
  auto f = [](int64_t x){return x*(x-1)/2;};
  for(auto x:mp)ans+=f(x.second);
  cout<<ans<<endl;
}