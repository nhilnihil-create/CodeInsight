#include <bits/stdc++.h>
using namespace std;

int main() {
int64_t A, B, C, X, Y;
cin >> A >> B >> C >> X >> Y;
C *= 2;
int Apiza, Bpiza, Cpiza;
  
const int64_t zero = 0;
int64_t nedan = 0;
int64_t ans = 9223372036854775806;
for( int64_t i = 0; i < 100001; i++ ){
    nedan = C*i + A*max(zero, X-i) + B*max(zero, Y-i);
    if( ans > nedan ){
      ans = nedan;
       Apiza = max(zero, X-i);
		Bpiza = max(zero, Y-i);
  		Cpiza = i*2;
    }
}
cout << ans << endl;
 // cout << Apiza << endl;
  //cout << Bpiza << endl;
  //cout << Cpiza << endl;
}
