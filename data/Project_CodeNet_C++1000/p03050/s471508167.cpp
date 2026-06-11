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
  ll n;
  cin >> n;
  map<ll,int> factor;
  for (ll i = 1;i*i <= n;i++){
    if (n%i == 0){
      factor[n/i]++;
    }
  }
  ll ans = 0;
  for (auto q: factor){
    //cout << q.first << endl;
    if (n/(q.first) < q.first-1) ans += (q.first-1);
  }
  cout << ans << endl;

 
 
 

  return 0;
}
