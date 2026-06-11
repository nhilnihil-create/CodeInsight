#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
  ll n,m;cin>>n>>m;
  ll sum = (n-2) * (m-2);
  if (n==1&&m==1){
    cout << 1 << endl;
    return 0;
  }
   else if (n==1 ||m == 1){
    cout << max(n,m) - 2 << endl;
    return 0;
  }
  else {
    cout << sum << endl;
  }
}