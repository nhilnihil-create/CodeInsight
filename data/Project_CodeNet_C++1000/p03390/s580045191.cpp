#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;


bool check(ll k, ll A, ll B){
  if(k*k/4 + B*B + B*k < A*B) return true;
  else return false;
}

int main(){
  int Q;
  cin >> Q;
  ll a[Q],b[Q];
  for(int i=0;i<Q;i++) cin >> a[i] >> b[i];

  for(int i=0;i<Q;i++){
    ll ans = 0;
    ll A = max(a[i], b[i]);
    ll B = min(a[i], b[i]);
    ans += 2 * (B - 1);

    ll l = 0;
    ll r = A - B;
    while(r - l > 1){
      ll mid = (l + r) / 2;
      if(check(mid,A,B)){
        l = mid;
      } else {
        r = mid;
      }
    }

    ans += l;
    cout << ans << endl;
  }
  return 0;
}