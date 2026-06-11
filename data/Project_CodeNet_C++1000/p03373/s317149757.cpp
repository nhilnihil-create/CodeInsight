#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  
  int total=0;
  int ans=1000000000;
  for(int i=0; i<=100000; i++){
    total = i*C*2 + max(0,X-i)*A + max(0,Y-i)*B;
    ans = min(ans,total);
  }
  
  cout << ans << endl;
  
}
