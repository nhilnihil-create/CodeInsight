#include <bits/stdc++.h>
using namespace std;
 
map<int64_t,int> prime;
 
void prime_list(int64_t n){
  for(int64_t i=2;i*i<=n;++i){
    while(n%i==0){
      ++prime[i];
      n=n/i;
    }
  }
  if(n!=1){
    ++prime[n];
  }
}
 
int main(){
  int N;
  cin>>N;
  for(int i=1;i<=N;++i){
    prime_list(i);
  }
 
  int a2=0,a4=0,a14=0,a24=0,a74=0;
  for(auto p:prime){
    if(p.second>=2) ++a2;
    if(p.second>=4) ++a4;
    if(p.second>=14) ++a14;
    if(p.second>=24) ++a24;
    if(p.second>=74) ++a74;
  }
 
  int ans=0;
  ans += a74;
  ans += a24*(a2-1);
  ans += a14*(a4-1);
  ans += ((a4*(a4-1))*(a2-2))/2;
  cout<<ans<<endl;
}