#include <bits/stdc++.h>
using namespace std;
long long f(long long a){
  long long ans = 0;
  for (long long i = a / 4 * 4; i <= a; i++){
    ans ^= i;
  }
  return ans;
}
int main(){
  long long A, B;
  cin >> A >> B;
  A--;
  long long ans = f(A) ^ f(B);
  cout << ans << endl;
}