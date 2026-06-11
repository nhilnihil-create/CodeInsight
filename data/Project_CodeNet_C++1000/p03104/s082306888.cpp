// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

int main() {
  ll a, b; cin >> a >> b;
  if (a==b) {
    cout << a << endl;
    return 0;
  }
  
  if (b-a==1) {
    cout << 1 << endl;
    return 0;
  }
  
  ll l = (a&1) ? a+1 : a; // lは偶数
  ll r = (b&1) ? b : b-1; // rは奇数
  ll C = ((r-l+1)/2)&1;
  if (a&1) C ^= a;
  if ((b&1)==0) C ^= b;
  cout << C << endl;
  return 0;
}
