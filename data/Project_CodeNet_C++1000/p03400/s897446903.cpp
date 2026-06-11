#include <bits/stdc++.h>
using namespace std;

int main() {
  int num,days,remain;
  cin >> num >> days >> remain;
  
  int ans = remain;
  for(int i = 0; i < num; i++) {
	int current; cin >> current;
    ans += (days / current);
    if(days % current != 0 ) {
      ans ++;
    }
  }
  cout << ans << endl;
  
  
  return 0;
}