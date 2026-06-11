// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int a, b, k; cin >> a >> b >> k;
  if (b-a+1 <= 2*k) {
    loop(i,a,b+1) cout << i << endl;
    return 0;
  }
  
  loop(i,a,a+k) cout << i << endl;
  loop(i,b-k+1,b+1) cout << i << endl;
  return 0;
}
