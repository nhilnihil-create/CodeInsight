#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int ans =0;
  for(int i=A; i<=B; i++){
    int a, b, c, d, e;
    a=i/10000;
    b=i/1000%10;
    e=i%10;
    d=i%100/10;
    
    if(a==e&&b==d)ans++;
  }
  
  cout << ans << endl;
}
