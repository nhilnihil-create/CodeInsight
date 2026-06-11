#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll n;
  cin >> n;
  ll root=pow(n,0.5);
  if(n==1){
    cout << 0 << endl;
    return 0;
  }
  ll sum=0;
  for(int i=1; i<=root; i++){
    if(n%i==0){
      ll like=n/i-1;
      ll ans=n/like;
      ll remain=n%like;
      if(ans==remain)sum+=like;
      like=i;
      ans=n/like;
      remain=n%like;
      if(ans==remain)sum+=like;
    }
  }
  cout << sum << endl;
}
  
  
  
