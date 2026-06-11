#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  for(int i=1; i<=3500; ++i) for(int j=i; j<=3500; ++j){
    ll r = 4*i*j - n*(i+j);
    ll l = (ll)n*i*j;
    if(r>0 && l%r == 0){
      cout << i << " " << j << " " << l/r << endl;
      return 0;
    }
  }
}