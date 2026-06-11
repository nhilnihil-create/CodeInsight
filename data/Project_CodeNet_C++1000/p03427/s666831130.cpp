#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main() {
    ll num; cin >> num;
  	
  	ll ans = 0;
    bool isAll9 = true;
  	while(num >= 1) {
 	 if(num < 10) {
       ans += num;
       if(!isAll9) ans--;
     } else {
       if(num % 10 != 9) isAll9 = false;
       ans += 9;
     }
      
     num /= 10; 
    }
  
    cout << ans << endl;

    return 0;
}