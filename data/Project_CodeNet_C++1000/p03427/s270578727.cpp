#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define repd(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repd(i,0,n)
typedef long long ll;


int main(){
  ll n;
  cin >> n;
  ll ans = 0;
  while(n >= 10){
    if(n % 10 < 9){
      n -= 10;
    }
    ans += 9;
    n/=10;
  }
  ans += n;
  cout << ans << endl;
  return 0;
}

