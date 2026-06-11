#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)


int main(){
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> v(n);
  vector<ll> sum(n+1,0);

  rep(i,n){
    cin >> v[i];
    sum[i+1] = sum[i] + v[i];
  }
  map<ll,int> cnt;
  ll ans = 0LL;
  for (int i = 0; i < n+1;i++){
    ans += cnt[ (sum[i])%m ];
    cnt[ sum[i]%m ]++;
  }
  cout << ans << endl;




  return 0; 
}

