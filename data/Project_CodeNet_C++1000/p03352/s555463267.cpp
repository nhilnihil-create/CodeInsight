#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll x;
  cin >> x;
  ll ans=1;
  for(int i=2;i<=40;i++){
    ll sum=i;
    while(sum<=x){
      sum*=i;
      if(sum<=x){
        ans=max(ans,sum);
      }
    }
  }
  cout << ans;
}
      