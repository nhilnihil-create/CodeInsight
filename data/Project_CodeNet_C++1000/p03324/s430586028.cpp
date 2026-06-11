#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n,d;
  cin>>d>>n;
  ll base=pow(100,d);
  ll ans;
  if(n==100){
    ans=base*(n+1);
  }else{
    ans=base*n;
  }
  cout<<ans<<endl;
}