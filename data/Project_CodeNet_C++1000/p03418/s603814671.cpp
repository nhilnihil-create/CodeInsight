#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll n,k,i;
  cin >> n >> k;
  if(k==0){
    cout << n*n << endl;
    return 0;
  }
  ll ans=(n-k)*(n-k+1)/2;
  for(i=k+1;i<=n;i++){
    ans+=(n-i+1)/i*(i-k);
    if((n-i+1)%i>=k){
      ll x=(n-i+1)%i;
      ans+=(x-k);
    }
  }
  cout << ans << endl;
}