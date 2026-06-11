#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 3000005;
int fac[MAX], inv[MAX], finv[MAX];
int mod = 1e9+7;

signed main(){
  //pre();
  int n,k;
  cin >> n >> k;
  
  int c = 0,d = 0, ans = 0;
  
  if(k%2){
    c = n/k;
    //cout << c << endl;
    ans = c*c*c;
  }
  else{
    d = n/(k/2);
    c = n/k; 
    //cout << d << endl;
    ans = pow(d-c, 3) + pow(c,3);
  }
  
  cout << ans << endl;
  return 0;
}
    
