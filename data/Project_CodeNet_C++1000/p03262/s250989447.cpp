#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int gcd(int a, int b){
   if(a%b == 0){
     return b;
   }else{
     return gcd(b, a%b);
   }
}

int main(){
  int N, X;
  cin >> N >> X;
  vector<ll> x(N), y(N);
  rep(i,N){
    cin >> x.at(i);
    y.at(i) = abs(x.at(i) - X);
  }
  int ans = y.at(0);
  rep(i,N){
    ans = gcd(ans,y.at(i));
    if(ans==1) break;
  }
  cout << ans;
  return 0;
}