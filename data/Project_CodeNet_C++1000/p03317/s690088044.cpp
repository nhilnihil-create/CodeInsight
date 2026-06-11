#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
  int n,k;
  cin >> n>>k;
  ll ans=1;
  n=max(0,n-k);
  k--;
  ans+=ceil(n*1.0/k);
  cout<<ans<<endl;
}
    
    
