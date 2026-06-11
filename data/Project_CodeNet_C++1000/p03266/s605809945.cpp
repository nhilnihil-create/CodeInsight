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
  int n,m;
  ll ans = 0LL;
  cin >> n >> m;
  map<int,int> mp;
  for (int i = 1; i <= n; i++){
    mp[i%m]++;
  }
  ans += (ll)mp[0]*mp[0]*mp[0];
  if (m%2 == 0){
    ans+= (ll)mp[m/2]*mp[m/2]*mp[m/2];
  }
  cout << ans << endl;

  


  return 0; 
}

