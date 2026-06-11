#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  ll n;
  cin >> n;
  ll l0 = 2;
  ll l1 = 1;
  ll ans;
  if(n==1){
    cout << 1 << endl;
    return 0;
  }
  for(int i=2; i<=n; ++i){
    ans = l0 + l1;
    l0 = l1;
    l1 = ans;
  }

  cout << ans;
  return 0;
}