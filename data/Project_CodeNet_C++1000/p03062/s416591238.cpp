#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)

int main(){
   int n;
   cin >> n;
   ll ans = 0;
   int cnt = 0;
   ll absmin = 1LL << 60;
   rep(i,n){
      ll x;
      cin >> x;
      if (x < 0) cnt++;
      ans += abs(x);
      absmin = min(absmin,abs(x));
   }
   if (cnt%2 == 0) cout << ans << endl;
   else cout << ans-2*absmin << endl;
   //cout << absmin << endl;
   //cout << ans << endl;
   return 0;
}
