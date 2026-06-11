#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> x(N);
  rep(i,N){
    cin >> x.at(i);
  }
  ll ans = 1e10;
  rep(i,N-K+1){
    ll xmin = x.at(i);
    ll xmax = x.at(i+K-1);
    if(xmin*xmax<0){
      ans = min(ans,xmax-2*xmin);
      ans = min(ans,2*xmax-xmin);
    }else{
      if(xmin>=0){
        ans = min(ans,xmax);
      }else{
        ans = min(ans,-xmin);
      }
    }
  }
  cout << ans;
  return 0;
}