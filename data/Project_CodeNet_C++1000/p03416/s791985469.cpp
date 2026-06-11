#include <bits/stdc++.h>
using namespace std;
int main() {
   long long A,B,ans=0;
   cin >> A >> B;
  for(int i=A; i<=B; i++){
    if((i%10 == i/10000) &&(i/1000 - (i/10000*10)) == ((i%100-i%10)/10)){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
