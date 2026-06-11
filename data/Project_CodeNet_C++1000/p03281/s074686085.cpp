#include<bits/stdc++.h>
#define rep(i,n) for(long long i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int f(int n){
  int div = 1;
  for(int i=1;i<n/2+1;++i){
    if(n%i == 0)div += 1;
  }
  return div;
}

int main(){
  int n;cin >> n;
  int ans = 0;
  for(int i = 11;i <= n;i += 2){
    if(f(i) == 8){
      ans += 1;
    }
  }
  cout << ans << endl;
}