#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){return b ? gcd(b,a%b):a;}

int main(){
  int n, x;
  cin >> n >> x;
  int ans;
  for(int i=0; i<n; ++i){
    int nx;
    cin >> nx;
    nx = abs(nx - x);
    if(i==0) ans = nx;
    else ans = gcd(ans, nx);
  }
  cout << ans << endl;
}