#include<iostream>
using namespace std;
int main(){
  long long k,a,b,ans;cin >> k >> a >> b;
  if(a+1 > k || b-a <= 2) cout << k+1 << endl;
  else{
    k -= a-1;ans = a+(b-a)*(k/2);k = k%2;
    if(k) ans++;
    cout << ans << endl;
  }
}
    