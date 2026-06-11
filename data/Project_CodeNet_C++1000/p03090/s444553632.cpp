#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main(){
  ll n;
  cin >> n;
  ll all = n*(n-1)/2;
  ll fill = n/2;
  cout << all - fill << endl;
  if(n%2==1){
    for(int i=1; i<=n; i++){
      for(int j=i+1; j<=n; j++){
        if(i+j==n)continue;
        cout << i << " " << j << endl;
      }
    }
  }
  else{
    for(int i=1; i<=n; i++){
      for(int j=i+1; j<=n; j++){
        if(i+j==n+1)continue;
        cout << i << " " << j << endl;
      }
    }
  }
  return 0;
}
  
  
  
  
