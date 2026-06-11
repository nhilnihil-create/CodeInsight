#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
  int n;
  std::cin >> n;
  std::vector<ll> A(n),B(n);
  rep(i,n)std::cin >> A[i];
  rep(i,n)std::cin >> B[i];

  std::vector<ll> ok(n,0);

  ll needs=0;
  bool cl=true;
  rep(i,n){
    if(A[i]<B[i]){
      ok[i]=A[i]-B[i];
      needs+=A[i]-B[i];
      cl=false;
    }
    if(A[i]>B[i]){
      needs+=A[i]-B[i];
      ok[i]+=A[i]-B[i];
    }
  }

  if(cl==false && needs<0){
    std::cout << "-1" << '\n';
    return 0;
  }

  sort(ok.begin(),ok.end());

  ll ans=0;
  ll stock=0;
  ll last=ok.size()-1;
  for (int i = 0; i < n; i++) {
    // std::cout <<"ok:"<<ok[i] << '\n';
    if(ok[i]>=0)break;
    stock+=ok[i];
    ans++;
    while (stock<0) {
      stock+=ok[last];
      last--;
      ans++;
    }
  }

  std::cout << ans << '\n';

  return 0;
}
