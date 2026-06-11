#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

uint64_t xorsum_from0(uint64_t n)
{
  if(n==0) return 0;
  if(n%2!=0)
  {
    if(n%4==1) return 1;
    else return 0;
  }
  if((n-1)%4==3) return n;
  else return 1^n; 
}

int main()
{
  uint64_t a,b;
  cin>>a>>b;

  ll ans=xorsum_from0(a-1)^xorsum_from0(b);
  cout<<ans<<endl;
}