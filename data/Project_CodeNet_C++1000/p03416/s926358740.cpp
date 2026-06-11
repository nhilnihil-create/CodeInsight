#include <bits/stdc++.h>
using namespace std;


int main() {
  int a, b;
  int ans = 0;
  cin >> a >> b;
  for(int i = a; i <= b;i++){
    int s = i%10, t = i/10000;
    int u = i/1000%10, z = i/10%10;
    if(s==t&&u==z)ans++;
  }
  cout << ans << endl;
}
